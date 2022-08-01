#ifndef GHWT_MIDI_INPUT_INPUT_DRIVER_HPP
#define GHWT_MIDI_INPUT_INPUT_DRIVER_HPP

#include "../midi_manager.hpp"
#include <span>
#include <vector>

namespace ghwt_midi {
	class MidiManager;
}

namespace ghwt_midi::input {
	struct InputChangeEvent {
		std::size_t button_count;
		std::size_t axis_count;
	};

	class InputDriver {
	private:
		MidiManager& _midi;

	public:
		InputDriver(MidiManager&);
		virtual ~InputDriver() = default;
		virtual void on_axis(std::size_t index, float value);
		virtual void on_button_down(std::size_t index);
		virtual void on_button_up(std::size_t index);
		virtual void on_input_change(InputChangeEvent&&);

	protected:
		MidiManager& get_midi_manager();
	};
}

#endif
