#include "simulation.hpp"
#include "os/os-window.hpp"
#include "os/os-events.hpp"
#include "os/os-event-dispatcher.hpp"

int main() {
	rpg::OSWindow osWindow;
	osWindow.CreateWindow(800, 600);
	osWindow.MakeContextCurrent();
	rpg::events::os::OSEventDispatcher osEventsDispatcher(osWindow.GetWindowHandle());
	while (!osWindow.ShouldClose()) {
		osWindow.ClearScreen(255, 255, 0);
		osWindow.SwapBuffers();
		osEventsDispatcher.PollEvents();
	}

	return 0;
}