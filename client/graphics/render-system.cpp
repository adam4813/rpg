#include "render-system.hpp"

#include <GL/glew.h>
#include <iostream>
#include <sstream>

namespace rpg {
	namespace graphics {
		void RenderSystem::ClearScreen(float red, float green, float blue) {
			glClearColor(red, green, blue, 1);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void RenderSystem::update(double delta) {
			std::stringstream ss;
			ss << "Render update @ " << delta << std::endl;
			std::cout << ss.str();
		}
	}
}
