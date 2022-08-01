#include "args.hpp"
#include "utils/constexpr_hash.hpp"
#include <iostream>
#include "input/drums_input_driver.hpp"
#include "input/guitar_input_driver.hpp"
#include "input/input_manager.hpp"
#include "midi_manager.hpp"
#include "sdl_manager.hpp"
#include <memory>
#include "utils/print.hpp"
#include <stdexcept>
#include <string>

using namespace ghwt_midi;
using namespace ghwt_midi::input;
using namespace ghwt_midi::utils;

void list_ports(MidiManager& midi) {
	const auto ports = midi.get_ports();

	if (ports.empty()) {
		throw std::runtime_error("No MIDI ports available");
	}

	for (const auto& p: ports) {
		println("{}: {}", p.index, p.name);
	}
}

void list_inputs(std::span<InputSource> inputs) {
	if (inputs.empty()) {
		throw std::runtime_error("No joystick inputs available");
	}

	for (const auto& i: inputs) {
		println("{}: {}", i.index, i.name);
	}
}

std::unique_ptr<InputDriver> create_input_driver(
	const Arguments& args,
	MidiManager& midi
) {
	auto type = args.type();
	switch (hash(type)) {
		case "guitar"_hash: return std::make_unique<GuitarInputDriver>(midi);
		case "drums"_hash: {
			return std::make_unique<DrumsInputDriver>(
				midi,
				std::vector<std::uint8_t> {
					43, // Green.
					40, // Red / snare.
					46, // Yellow / hi-hat cymbal.
					47, // Blue.
					49, // Orange / crash cymbal.
					36, // Pedal / kick bass.
					0, // Plus / start.
					0, // Minus / select.
				}
			);
		}
	}

	throw std::runtime_error(f("Unknown instrument type: {}", type));
}

int main(int argc, char** argv) {
	try {
		Arguments args;
		args.parse(argc, argv);

		if (args.list_ports()) {
			MidiManager midi;
			list_ports(midi);
			return 0;
		}

		if (args.list_inputs()) {
			SdlManager sdl;
			auto inputs = sdl.get_inputs();
			list_inputs(inputs);
			return 0;
		}

		MidiManager midi;
		auto input_driver = std::make_unique<DrumsInputDriver>(
			midi,
			std::vector<std::uint8_t> {

			}
		);
		SdlManager sdl;
		InputManager input(sdl, midi, create_input_driver(args, midi));

		midi.open_port(args.port());
		input.set_input(args.input());
		input.main_loop();

		return 0;
	} catch (const RtMidiError& e) {
		eprintln("Fatal error: {}", e.getMessage());
	} catch (const std::runtime_error& e) {
		std::string message(e.what());
		eprintln("Fatal error: {}", message);
	}

	return 1;
}
