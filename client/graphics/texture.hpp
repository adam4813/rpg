#pragma once
#include <GL/glew.h>

namespace rpg {
	namespace graphics {
		class Texture {
		private:
			GLuint texture_id;
		public:
			GLuint getTextureId() {
				return this->texture_id;
			}
		};
	}
}