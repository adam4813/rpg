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

		void ClearScreen(int red, int green, int blue);

		void SwapBuffers();
	private:
		GLFWwindow* window;
	};
}