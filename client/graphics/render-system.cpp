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

		RenderSystem::RenderSystem(OSWindow& osWindow) : osWindow(osWindow) {}

		void RenderSystem::update(double delta) {
			static double accum = delta;
			accum += delta;
			this->ClearScreen(1, fmod(accum, 1), 1 - fmod(accum, 1));


			osWindow.SwapBuffers();
		}
	}
}
