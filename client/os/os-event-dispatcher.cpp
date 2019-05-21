#include <GLFW/glfw3.h>
#include "os-event-dispatcher.hpp"
#include "os-events.hpp"
#include "events/event-dispatcher.hpp"


namespace rpg {
	namespace events {
		namespace os {
			using KeyDispatcher = EventDispatcher<KeyEvent>;
			using CharDispatcher = EventDispatcher<CharEvent>;
			static auto keyDispatcher = KeyDispatcher::Get();
			static auto charDispatcher = CharDispatcher::Get();
			OSEventDispatcher::OSEventDispatcher(GLFWwindow* window) : window(window) {
				glfwSetKeyCallback(this->window, [] (GLFWwindow*, int key, int, int action, int mods) {
					keyDispatcher->Emit(std::make_shared<KeyEvent>(KeyEvent{ key, action, mods }));
								   });
				glfwSetCharModsCallback(this->window, [] (GLFWwindow*, unsigned int key, int mods) {
					charDispatcher->Emit(std::make_shared<CharEvent>(CharEvent{ key, mods }));
										});
			}

			void OSEventDispatcher::PollEvents() {
				glfwPollEvents();
			}
		}
	}
}
