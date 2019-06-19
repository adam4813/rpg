#pragma once

#include <set>
#include <memory>

#include <util\worker-thread.hpp>

#include "graphics/render-system.hpp"

namespace rpg {
	class Game {
	public:
		Game();

		void init();

		void update(double delta);

		void await();
	private:
		graphics::RenderSystem renderSystem;
		std::set<std::unique_ptr<WorkerThread>> updateThreads;
	};
}
