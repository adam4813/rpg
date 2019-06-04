#include <simulation.hpp>
#include <events/event-dispatcher.hpp>
#include <events/event-queue.hpp>
#include <script/script-system.hpp>

#include "os/os-window.hpp"
#include "os/os-events.hpp"
#include "os/os-event-dispatcher.hpp"
#include <util/worker-thread.hpp>

#include <iostream>
#include <sstream>
#include <GLFW\glfw3.h>

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

void renderUpdate(double delta) {
	std::stringstream ss;
	ss << "Render update @ " << delta << std::endl;
	std::cout << ss.str();
}
void soundUpdate(double delta) {
	std::stringstream ss;
	ss << "Sound update @ " << delta << std::endl;
	std::cout << ss.str();
}
void physicsUpdate(double delta) {
	std::stringstream ss;
	ss << "Physics update @ " << delta << std::endl;
	std::cout << ss.str();
}

int main() {
	rpg::OSWindow osWindow;
	osWindow.CreateWindow(800, 600);
	osWindow.MakeContextCurrent();
	rpg::events::os::OSEventDispatcher osEventsDispatcher(osWindow.GetWindowHandle());

	rpg::Test test;

	rpg::script::ScriptSystem script;
	script.init();

	rpg::WorkerThread* renderWorker = new rpg::WorkerThread(std::function<rpg::updateable>(renderUpdate));
	renderWorker->spawn();
	rpg::WorkerThread* soundWorker = new rpg::WorkerThread(std::function<rpg::updateable>(soundUpdate));
	soundWorker->spawn();
	rpg::WorkerThread* physicsWorker = new rpg::WorkerThread(std::function<rpg::updateable>(physicsUpdate));
	physicsWorker->spawn();

	double time = glfwGetTime();
	double delta = time;
	double lastTime = delta;

	while (!osWindow.ShouldClose()) {
		time = glfwGetTime();
		delta = time - lastTime;
		lastTime = time;
		test.ProcessEventQueue();

		renderWorker->setDelta(delta);
		soundWorker->setDelta(delta);
		physicsWorker->setDelta(delta);

		// Do main thread things here

		renderWorker->wait();
		soundWorker->wait();
		physicsWorker->wait();

		osWindow.SwapBuffers();
		osEventsDispatcher.PollEvents();
	}

	renderWorker->join();
	delete renderWorker;
	soundWorker->join();
	delete soundWorker;
	physicsWorker->join();
	delete physicsWorker;

	return 0;
}
