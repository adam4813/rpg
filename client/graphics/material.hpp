#pragma once

#include <glm/glm.hpp>

namespace rpg {
	namespace graphics {
		typedef glm::vec4 Color;
		class Texture;

		class Material {
		private:
			Color color;
			Texture* texture;
		public:
			void bind(unsigned short texture_unit = 0);
		};
	}
}