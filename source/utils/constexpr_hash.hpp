#ifndef GHWT_MIDI_UTILS_CONSTEXPR_HASH_HPP
#define GHWT_MIDI_UTILS_CONSTEXPR_HASH_HPP

#include <cstddef>
#include <string_view>

namespace ghwt_midi::utils {
	constexpr std::size_t hash(const char* s) {
		auto c = *s;
		return c == '\0'
			? 5381
			: static_cast<std::size_t>(c) + 33 * hash(s + 1);
	}

	constexpr std::size_t hash(std::string_view s) {
		return hash(s.data());
	}

	constexpr std::size_t operator "" _hash(const char* s, std::size_t) {
		return hash(s);
	}
}

#endif
