#ifndef GHWT_MIDI_INPUT_DRUMS_INPUT_DRIVER_HPP
#define GHWT_MIDI_INPUT_DRUMS_INPUT_DRIVER_HPP

#include "input_driver.hpp"
#include <vector>

namespace ghwt_midi::input {
	class DrumsInputDriver final: public InputDriver {
	private:
		std::vector<std::uint8_t> _button2pitch;

	public:
		DrumsInputDriver(
			MidiManager& midi,
			std::vector<std::uint8_t>&& button2pitch
		);
		std::uint8_t get_pitch(std::size_t index) const;
		void set_pitch(std::size_t index, std::uint8_t value);
		virtual void on_button_down(std::size_t index) override;
		virtual void on_input_change(InputChangeEvent&&) override;
	};
}

#endif
