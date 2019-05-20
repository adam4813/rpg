#include "simulation.hpp"
#include "os/os-window.hpp"
#include "os/os-events.hpp"
#include "os/os-event-dispatcher.hpp"

#include "events/event-dispatcher.hpp"
#include "events/event-queue.hpp"

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

	rpg::Test test;

	while (!osWindow.ShouldClose()) {
		test.ProcessEventQueue();
		osWindow.ClearScreen(255, 255, 0);
		osWindow.SwapBuffers();
		osEventsDispatcher.PollEvents();
	}

	return 0;
}