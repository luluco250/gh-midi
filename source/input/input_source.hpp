#ifndef GHWT_MIDI_INPUT_INPUT_SOURCE_HPP
#define GHWT_MIDI_INPUT_INPUT_SOURCE_HPP

#include <cstddef>
#include <string>
#include <cstdint>

namespace ghwt_midi::input {
	struct InputSource final {
		std::uint32_t index;
		std::string name;
	};
}

#endif
