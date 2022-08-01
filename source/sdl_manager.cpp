#include <array>
#include <cstddef>
#include "input/input_source.hpp"
#include "sdl_manager.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <vector>

namespace ghwt_midi {
	SdlManager::SdlManager() {
		if (SDL_Init(SDL_INIT_JOYSTICK) != 0) {
			std::array<char, 1024> message_buffer;
			SDL_GetErrorMsg(message_buffer.data(), message_buffer.size());
			throw std::runtime_error(message_buffer.data());
		}
	}

	SdlManager::~SdlManager() {
		SDL_Quit();
	}

	std::vector<input::InputSource> SdlManager::get_inputs() const {
		std::vector<input::InputSource> sources(SDL_NumJoysticks());

		for (std::size_t i = 0; i < sources.size(); ++i) {
			auto& source = sources[i];
			source.index = i;
			source.name = SDL_JoystickNameForIndex(i);
		}

		return sources;
	}
}
