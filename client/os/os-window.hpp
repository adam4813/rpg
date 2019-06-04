#pragma once

struct GLFWwindow;

namespace rpg {
	class OSWindow {
	public:
		OSWindow();
		~OSWindow();

		bool CreateWindow(const unsigned int width, const unsigned int height);

		void MakeContextCurrent();

		bool ShouldClose();

		GLFWwindow* GetWindowHandle();

		void SwapBuffers();
	private:
		static void FrameBufferResizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* window;
	};
}
