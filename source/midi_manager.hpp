#ifndef GHWT_MIDI_MIDI_HPP
#define GHWT_MIDI_MIDI_HPP

#include <array>
#include <cstdint>
#include <rtmidi/RtMidi.h>
#include <string>
#include <vector>

namespace ghwt_midi {
	struct MidiPort final {
		std::uint32_t index;
		std::string name;
	};

	class MidiManager final {
	private:
		RtMidiOut _midi_out;
		std::array<std::uint8_t, 3> _message;

	public:
		std::vector<MidiPort> get_ports();
		void open_port(std::uint32_t port);
		void send(std::uint8_t a);
		void send(std::uint8_t a, std::uint8_t b);
		void send(std::uint8_t a, std::uint8_t b, std::uint8_t c);
	};
}

#endif
