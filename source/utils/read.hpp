#ifndef GHWT_MIDI_UTILS_READ_HPP
#define GHWT_MIDI_UTILS_READ_HPP

#include "concepts.hpp"
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

namespace ghwt_midi::utils {
	std::string read();

	std::string read(std::string_view prompt);

	template<typename T>
	auto make_choice(
		std::string_view prompt,
		Callable<std::optional<T>, std::string_view> auto transformer
	) {
		while (true) {
			auto transformed = transformer(read(prompt));
			if (transformed) return *transformed;
		}
	}
}

#endif
