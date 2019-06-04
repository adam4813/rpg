#pragma once

#include <future>
#include <thread>
#include <functional>

namespace rpg {
	typedef void(updateable)(double);

	class WorkerThread {
	public:
		WorkerThread(std::function<updateable> updateFunction) : updateFunction(updateFunction) {
			nextFuture = this->nextPromise.get_future();
		}

		~WorkerThread() {}

		void spawn() {
			this->thread = std::thread(&WorkerThread::update, this);
		}

		void update() {
			while (!this->shouldJoin) {
				this->nextFuture.wait();
				double delta = this->nextFuture.get();

				this->updateFunction(delta);

				this->nextPromise.swap(std::promise<double>());
				nextFuture = nextPromise.get_future();
				updatePromise.set_value();
			}
		}

		void setDelta(double delta) {
			this->nextPromise.set_value(delta);
		}

		void join() {
			this->shouldJoin = true;
			this->thread.join();
		}

		void wait() {
			auto updateFuture = this->updatePromise.get_future();
			updateFuture.wait();
			this->updatePromise.swap(std::promise<void>());
		}

	private:
		std::function<updateable> updateFunction;
		std::future<double> nextFuture;
		std::promise<double> nextPromise;
		std::promise<void> updatePromise;
		std::thread thread;
		bool shouldJoin = false;
	};
}
