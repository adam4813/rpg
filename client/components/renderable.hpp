#pragma once

#include <memory>
#include <components/component-types.hpp>
#include "../graphics/material.hpp"
#include "../graphics/mesh.hpp"

namespace rpg {
	namespace {
		struct renderable_impl {
			renderable_impl(std::shared_ptr<graphics::Mesh> mesh, std::shared_ptr<graphics::Material> material) : mesh(mesh), material(material) {}
			std::shared_ptr<graphics::Mesh> mesh;
			std::shared_ptr<graphics::Material> material;
		};
	}

	using Renderable = std::shared_ptr<renderable_impl>;
	MAKE_COMPONENTTYPE_MAP(Renderable);
}
