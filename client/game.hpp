#pragma once

#include <set>
#include <memory>

#include <util\worker-thread.hpp>

#include "graphics/render-system.hpp"
#include "os/os-window.hpp"

namespace rpg {
	class Game {
	public:
		Game(OSWindow& osWindow);

		void init();

		void update(double delta);

		void await();
	private:
		graphics::RenderSystem renderSystem;
		std::set<std::unique_ptr<WorkerThread>> updateThreads;
		OSWindow& osWindow;
	};
}
