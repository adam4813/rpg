#include "material.hpp"
#include "texture.hpp"
#include <GL/glew.h>

namespace rpg {
	namespace graphics {
		void Material::bind(unsigned short texture_unit) {
			glActiveTexture(GL_TEXTURE0 + texture_unit);
			glBindTexture(GL_TEXTURE_2D, this->texture->getTextureId());
		}
	}
}