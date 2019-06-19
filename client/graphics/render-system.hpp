#pragma once
#include <memory>

#include <util/component-map.hpp>

#include "../components/renderable.hpp"

namespace rpg {
	typedef ComponentMap<std::shared_ptr<Renderable>> RenderableMap;
	namespace graphics {
		class RenderSystem {
		private:
			static void ClearScreen(float red, float green, float blue);

		public:
			void update(double delta);
		};
	}
}
