#pragma once

#include "component-types.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace rpg {
	using Position = glm::vec3;
	using Orientation = glm::quat;
	using Health = int;

	MAKE_COMPONENTTYPE_MAP(Position);
	MAKE_COMPONENTTYPE_MAP(Orientation);
	MAKE_COMPONENTTYPE_MAP(Health);
}
