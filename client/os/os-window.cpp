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

		glViewport(0, 0, width, height);
		glfwSetFramebufferSizeCallback(window, OSWindow::FrameBufferResizeCallback);
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

	void OSWindow::SwapBuffers() {
		glfwSwapBuffers(this->window);
	}

	void OSWindow::FrameBufferResizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}
