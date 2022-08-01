#ifndef GHWT_MIDI_SDL_HPP
#define GHWT_MIDI_SDL_HPP

#include "input/input_source.hpp"
#include <vector>

namespace ghwt_midi {
	class SdlManager final {
	public:
		SdlManager();
		~SdlManager();
		SdlManager(SdlManager&&) = default;
		SdlManager(const SdlManager&) = delete;
		SdlManager& operator=(SdlManager&&) = default;
		SdlManager& operator=(const SdlManager&) = delete;
		std::vector<input::InputSource> get_inputs() const;
	};
}

#endif
