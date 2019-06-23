#pragma once
#include <util/component-map.hpp>
#include <memory>

namespace rpg {
	/// Returns the name of an component on compile time
	template<class TYPE> constexpr const char* GetTypeName(void) { return "UNKNOWN"; }
	/// Returns the name of a resource type on Compile time
	template<class TYPE> constexpr const char* GetTypeEXT(void) { return "UNKNOWN"; }
	/// Returns the name of a resource type on Compile time
	template<class TYPE> ComponentMap<TYPE> GetComponentTypeMap(void) { return "UNKNOWN"; }

#define MAKE_EXTTYPE(a, b) \
	template<> inline constexpr const char* GetTypeName<a>() { return #a; } \
	template<> inline constexpr const char* GetTypeEXT<a>() { return b; }

#define MAKE_COMPONENTTYPE_MAP(a) \
	template<> inline constexpr ComponentMap<a> GetComponentTypeMap<a>() { return ComponentMap<a>(); } \
	template<> inline constexpr const char* GetTypeName<a>() { return #a; }
}
