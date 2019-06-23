#pragma once

#include <future>
#include <thread>
#include <functional>
#include <iostream>
#include <optional>

namespace rpg {
	typedef void(updateable)(double);

	class WorkerThread {
	public:
		WorkerThread(std::function<updateable> updateFunction, std::optional<std::function<void()>> spawnFunction = {}) : updateFunction(updateFunction), spawnFunction(spawnFunction) {
			nextFuture = this->nextPromise.get_future();
		}

		~WorkerThread() {
			std::cout << "worker join" << std::endl;
			this->joinThread();
		}

		void spawnThread() {
			this->thread = std::thread(&WorkerThread::updateLoop, this);
		}

		// 500ms shouldJoin check. Should only come into play at program exit.
		void updateLoop() {
			if (this->spawnFunction.has_value()) {
				this->spawnFunction.value()();
			}
			while (!this->shouldJoin) {
				auto status = this->nextFuture.wait_for(std::chrono::milliseconds(500));
				if (status != std::future_status::ready) {
					continue;
				}
				double delta = this->nextFuture.get();

				this->updateFunction(delta);

				this->nextPromise.swap(std::promise<double>());
				nextFuture = nextPromise.get_future();
				updatePromise.set_value();
			}
		}

		// Causes updateLoop to do an iteration.
		void setDelta(double delta) {
			this->nextPromise.set_value(delta);
		}

		void joinThread() {
			this->shouldJoin = true;
			this->thread.join();
		}

		void awaitResult() {
			auto updateFuture = this->updatePromise.get_future();
			updateFuture.wait();
			this->updatePromise.swap(std::promise<void>());
		}

	private:
		std::function<updateable> updateFunction;
		std::optional<std::function<void()>> spawnFunction;
		std::future<double> nextFuture;
		std::promise<double> nextPromise;
		std::promise<void> updatePromise;
		std::thread thread;
		bool shouldJoin = false;
	};
}
