#include <algorithm>
#include "input_driver.hpp"
#include "../midi_manager.hpp"
#include "../utils/print.hpp"
#include "../sdl_manager.hpp"
#include <vector>

namespace ghwt_midi::input {
	using namespace utils;

	InputDriver::InputDriver(MidiManager& midi): _midi(midi) {}

	void InputDriver::on_axis(std::size_t, float) {}

	void InputDriver::on_button_down(std::size_t) {}

	void InputDriver::on_button_up(std::size_t) {}

	void InputDriver::on_input_change(InputChangeEvent&&) {}

	MidiManager& InputDriver::get_midi_manager() {
		return _midi;
	}
}
