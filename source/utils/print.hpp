#ifndef GHWT_MIDI_UTILS_PRINT_HPP
#define GHWT_MIDI_UTILS_PRINT_HPP

#include <fmt/core.h>
#include <iostream>
#include <string_view>

namespace ghwt_midi::utils {
	constexpr std::string_view newline =
	#if WIN32
		"\r\n"
	#else
		"\n"
	#endif
	;

	template<typename... T>
	inline constexpr void print(fmt::format_string<T...> s, T&&... args) {
		fmt::print(s, args...);
	}

	inline void print(std::string_view s) {
		std::cout << s;
	}

	template<typename... T>
	inline void println(fmt::format_string<T...> s, T&&... args) {
		fmt::print(s, args...);
		std::cout << newline;
	}

	inline void println(std::string_view s) {
		std::cout << s << newline;
	}

	inline void println() {
		std::cout << newline;
	}

	template<typename... T>
	inline void eprintln(fmt::format_string<T...> s, T&&... args) {
		fmt::print(stderr, s, args...);
		std::cerr << newline;
	}

	inline void eprintln(std::string_view s) {
		std::cerr << s << newline;
	}

	inline void eprintln() {
		std::cerr << newline;
	}

	template<typename... T>
	inline constexpr void eprint(fmt::format_string<T...> s, T&&... args) {
		fmt::print(stderr, s, args...);
	}

	inline void eprint(std::string_view s) {
		std::cerr << s;
	}

	template<typename... T>
	inline std::string f(fmt::format_string<T...> s, T&&... args) {
		return fmt::format(s, args...);
	}
}

#endif
