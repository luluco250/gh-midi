#include "drums_input_driver.hpp"
#include "../utils/print.hpp"

namespace ghwt_midi::input {
	using namespace utils;

	DrumsInputDriver::DrumsInputDriver(
		MidiManager& midi,
		std::vector<std::uint8_t>&& button2pitch
	):
		InputDriver(midi),
		_button2pitch(button2pitch) {}

	std::uint8_t DrumsInputDriver::get_pitch(std::size_t index) const {
		return _button2pitch[index];
	}

	void DrumsInputDriver::set_pitch(std::size_t index, std::uint8_t value) {
		_button2pitch[index] = value;
	}

	void DrumsInputDriver::on_button_down(std::size_t index) {
		auto& midi = get_midi_manager();
		auto pitch = _button2pitch[index];
		midi.send(153, pitch, 127);
		midi.send(137, pitch, 0);

		println("Button {} -> {}", index, pitch);
	}

	void DrumsInputDriver::on_input_change(InputChangeEvent&& e) {
		_button2pitch.resize(e.button_count);
	}
}
