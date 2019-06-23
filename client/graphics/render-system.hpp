#pragma once
#include <memory>

#include <util/component-map.hpp>

#include "../components/renderable.hpp"
#include "../os/os-window.hpp"

namespace rpg {
	typedef ComponentMap<std::shared_ptr<Renderable>> RenderableMap;
	namespace graphics {
		class RenderSystem {
		public:
			RenderSystem(OSWindow& osWindow);
			void update(double delta);

		private:
			static void ClearScreen(float red, float green, float blue);
			OSWindow& osWindow;
		};
	}
}
