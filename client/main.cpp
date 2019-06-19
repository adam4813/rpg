#include <simulation.hpp>
#include <events/event-dispatcher.hpp>
#include <events/event-queue.hpp>
#include <script/script-system.hpp>

#include "os/os-window.hpp"
#include "os/os-events.hpp"
#include "os/os-event-dispatcher.hpp"

#include <GLFW\glfw3.h>
#include "game.hpp"

namespace rpg {
	class Test : public events::EventQueue<events::os::KeyEvent> {
	public:
		void On(std::shared_ptr<events::os::KeyEvent> event) {
			this->quit = true;
		}
		void ProcessEventQueue() {
			EventQueue<events::os::KeyEvent>::ProcessEventQueue();
		}
	private:
		bool quit = false;
	};
}

int main() {
	rpg::OSWindow osWindow;
	osWindow.CreateWindow(800, 600);
	osWindow.MakeContextCurrent();
	rpg::events::os::OSEventDispatcher osEventsDispatcher(osWindow.GetWindowHandle());

	rpg::Game game;
	game.init();

	rpg::Test test;

	rpg::script::ScriptSystem script;
	script.init();

	double time = glfwGetTime();
	double delta = time;
	double lastTime = delta;

	while (!osWindow.ShouldClose()) {
		time = glfwGetTime();
		delta = time - lastTime;
		lastTime = time;
		test.ProcessEventQueue();

		game.update(delta);

		// Do main thread things here

		game.await();
		osWindow.SwapBuffers();
		osEventsDispatcher.PollEvents();
	}


	return 0;
}
