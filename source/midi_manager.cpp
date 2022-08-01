#include <cstdint>
#include "midi_manager.hpp"
#include "utils/print.hpp"
#include <vector>

namespace ghwt_midi {
	using namespace utils;

	std::vector<MidiPort> MidiManager::get_ports() {
		std::vector<MidiPort> ports(_midi_out.getPortCount());

		for (std::size_t i = 0; i < ports.size(); ++i) {
			auto& port = ports[i];
			port.index = i;
			port.name = _midi_out.getPortName(i);
		}

		return ports;
	}

	void MidiManager::open_port(std::uint32_t port) {
		_midi_out.openPort(port);
	}

	void MidiManager::send(std::uint8_t a) {
		_message[0] = a;
		_midi_out.sendMessage(_message.data(), 1);
		println("Midi output: {}", a);
	}

	void MidiManager::send(std::uint8_t a, std::uint8_t b) {
		_message[0] = a;
		_message[1] = b;
		_midi_out.sendMessage(_message.data(), 2);
		println("Midi output: {} {}", a, b);
	}

	void MidiManager::send(std::uint8_t a, std::uint8_t b, std::uint8_t c) {
		_message[0] = a;
		_message[1] = b;
		_message[2] = c;
		_midi_out.sendMessage(_message.data(), 3);
		println("Midi output: {} {} {}", a, b, c);
	}
}
