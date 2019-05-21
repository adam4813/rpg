#pragma once

struct GLFWwindow;

namespace rpg {
	namespace events {
		namespace os {
			class OSEventDispatcher {
			public:
				OSEventDispatcher(GLFWwindow* window);

				void PollEvents();
			private:
				GLFWwindow* window;
			};
		}
	}
}
