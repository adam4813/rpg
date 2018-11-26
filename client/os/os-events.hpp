#pragma once

namespace rpg {
	namespace events {
		namespace os {
			struct KeyEvent {
				int key, action, mods;
			};
			struct CharEvent {
				unsigned int key;
				int mods;
			};
		}
	}
}