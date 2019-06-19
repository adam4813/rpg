#pragma once

#include <glm/glm.hpp>
#include <memory>

namespace rpg {
	namespace graphics {
		typedef glm::vec4 Color;
		class Texture;

		class Material {
		private:
			Color color;
			std::shared_ptr<Texture> texture;
		public:
			void bind(unsigned short texture_unit = 0);
		};
	}
}
