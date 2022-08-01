#include "input_manager.hpp"
#include <fmt/core.h>
#include <memory>
#include "../utils/print.hpp"
#include "../sdl_manager.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <utility>

namespace ghwt_midi::input {
	using namespace utils;

	InputManager::InputManager(
		SdlManager& sdl,
		MidiManager& midi,
		std::unique_ptr<InputDriver>&& input_driver
	):
		_sdl(sdl),
		_midi(midi),
		_input_driver(std::move(input_driver)) {
		if (SDL_Init(SDL_INIT_JOYSTICK) < 0) {
			std::string message(SDL_GetError());
			throw std::runtime_error(
				f("Failed to initialize SDL: {}", message)
			);
		}
	}

	InputManager::~InputManager() {
		SDL_Quit();
	}

	std::vector<InputSource> InputManager::get_inputs() {
		return _sdl.get_inputs();
	}

	void InputManager::set_input(int index) {
		_joystick = SDL_JoystickOpen(index);
		if (_joystick == nullptr) {
			throw std::runtime_error(f("Failed to open joystick #{}", index));
		}

		auto button_count = SDL_JoystickNumButtons(_joystick);
		auto axis_count = SDL_JoystickNumAxes(_joystick);

		if (_input_driver) {
			_input_driver->on_input_change({
				.button_count = std::size_t(button_count),
				.axis_count = std::size_t(axis_count),
			});
		}
	}

	void InputManager::main_loop() {
		SDL_Event event;

		while (true) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) return;
				if (!_input_driver) break;

				switch (event.type) {
					case SDL_JOYAXISMOTION: {
						auto index = event.jaxis.axis;
						auto value = event.jaxis.value;
						_input_driver->on_axis(index, value);
						break;
					}
					case SDL_JOYBUTTONDOWN: {
						auto index = event.jbutton.button;
						_input_driver->on_button_down(index);
						break;
					}
					case SDL_JOYBUTTONUP: {
						auto index = event.jbutton.button;
						_input_driver->on_button_up(index);
						break;
					}
				}
			}\
		}
	}
}
