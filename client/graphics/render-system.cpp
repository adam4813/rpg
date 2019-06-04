#include "render-system.hpp"

#include <GL/glew.h>

namespace rpg {
	namespace graphics {
		void RenderSystem::ClearScreen(float red, float green, float blue) {
			glClearColor(red, green, blue, 1);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
}
