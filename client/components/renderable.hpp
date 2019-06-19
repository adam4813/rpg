#pragma once

#include <memory>
#include "../graphics/material.hpp"
#include "../graphics/mesh.hpp"

namespace rpg {
	struct Renderable {
		Renderable(std::shared_ptr<graphics::Mesh> mesh, std::shared_ptr<graphics::Material> material) : mesh(mesh), material(material) {}
		std::shared_ptr<graphics::Mesh> mesh;
		std::shared_ptr<graphics::Material> material;
	};
}
