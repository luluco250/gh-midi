#ifndef GHWT_MIDI_INPUT_GUITAR_INPUT_DRIVER_HPP
#define GHWT_MIDI_INPUT_GUITAR_INPUT_DRIVER_HPP

#include <bitset>
#include "input_driver.hpp"
#include "../midi_manager.hpp"

namespace ghwt_midi::input {
	class GuitarInputDriver final: public InputDriver {
	private:
		std::uint8_t _frets;

	public:
		GuitarInputDriver(MidiManager& midi);
		virtual void on_button_down(std::size_t index) override;
		virtual void on_button_up(std::size_t index) override;
		virtual void on_input_change(InputChangeEvent&&) override;
	};
}

#endif
