#include "os-window.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace rpg {
	OSWindow::OSWindow() : window(nullptr) {}

	OSWindow::~OSWindow() {}

	bool OSWindow::CreateWindow(const unsigned int width, const unsigned int height) {
		if (!glfwInit()) {
			return false;
		}
		if (!glewInit()) {
			return false;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

		if (!(this->window = glfwCreateWindow(width, height, "MMORPG", NULL, NULL))) {
			return false;
		}

		return true;
	}
	void OSWindow::MakeContextCurrent() {
		glfwMakeContextCurrent(this->window);
	}
	bool OSWindow::ShouldClose() {
		return glfwWindowShouldClose(this->window);
	}
	GLFWwindow* OSWindow::GetWindowHandle() {
		return this->window;
	}
	void OSWindow::ClearScreen(int red, int green, int blue) {
		glClearColor(red, green, blue, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void OSWindow::SwapBuffers() {
		glfwSwapBuffers(this->window);
	}
}
