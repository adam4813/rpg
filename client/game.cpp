#include "game.hpp"

#include <iostream>
#include <sstream>

namespace rpg {
	Game::Game(OSWindow& osWindow) : osWindow(osWindow), renderSystem(osWindow) {}

	void Game::init() {
		this->updateThreads.emplace(
			std::make_unique<WorkerThread>(
				[this] (double delta) {
					this->renderSystem.update(delta);
				},
				[this] () {
					this->osWindow.MakeContextCurrent();
				})
		);
		this->updateThreads.emplace(
			std::make_unique<WorkerThread>(
				[this] (double delta) {
					std::stringstream ss;
					ss << "Physics update @ " << delta << std::endl;
					std::cout << ss.str();
				})
		);
		this->updateThreads.emplace(
			std::make_unique<WorkerThread>(
				[this] (double delta) {
					std::stringstream ss;
					ss << "Sound update @ " << delta << std::endl;
					std::cout << ss.str();
				})
		);
		for (const auto& worker : this->updateThreads) {
			worker->spawnThread();
		}
	}

	void Game::update(double delta) {
		for (const auto& worker : this->updateThreads) {
			worker->setDelta(delta);
		}
	}

	void Game::await() {
		for (const auto& worker : this->updateThreads) {
			worker->awaitResult();
		}
	}
}
