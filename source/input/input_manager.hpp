#ifndef GHWT_MIDI_INPUT_INPUT_HPP
#define GHWT_MIDI_INPUT_INPUT_HPP

#include "input_driver.hpp"
#include <memory>
#include "../midi_manager.hpp"
#include "../sdl_manager.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

namespace ghwt_midi::input {
	class InputManager final {
	private:
		SdlManager& _sdl;
		MidiManager& _midi;
		SDL_Joystick* _joystick;
		std::unique_ptr<InputDriver> _input_driver;

	public:
		InputManager(
			SdlManager& sdl,
			MidiManager& midi,
			std::unique_ptr<InputDriver>&& input_driver
		);
		~InputManager();
		std::vector<InputSource> get_inputs();
		void set_input(int index);
		void set_input_driver(std::unique_ptr<InputDriver>&& value);
		void main_loop();
	};
}

#endif
