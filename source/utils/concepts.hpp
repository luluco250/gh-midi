#ifndef GHWT_MIDI_UTILS_CONCEPTS_HPP
#define GHWT_MIDI_UTILS_CONCEPTS_HPP

namespace ghwt_midi::utils {
	template<typename Func, typename Ret, typename... Args>
	concept Callable = requires (Func f, Args... args) {
		{ f(args...) } -> std::same_as<Ret>;
	};
}

#endif
