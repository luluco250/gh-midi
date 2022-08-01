#include "guitar_input_driver.hpp"
#include "../utils/print.hpp"

namespace ghwt_midi::input {
	using namespace utils;

	constexpr std::size_t Green = 0;
	constexpr std::size_t Red = 1;
	constexpr std::size_t Yellow = 2;
	constexpr std::size_t Blue = 3;
	constexpr std::size_t Orange = 4;
	constexpr std::size_t StrumUp = 8;
	constexpr std::size_t StrumDown = 5;
	constexpr std::size_t StarPower = 7;
	constexpr std::size_t Pause = 6;
	constexpr std::uint8_t Offset = 64;

	GuitarInputDriver::GuitarInputDriver(MidiManager& midi):
		InputDriver(midi),
		_frets(0) {}

	void GuitarInputDriver::on_button_down(std::size_t index) {
		auto& midi = get_midi_manager();

		switch (index) {
			case Green:
			case Red:
			case Yellow:
			case Blue:
			case Orange: {
				_frets |= 1 << index;

				midi.send(123);
				// for (auto i = 0; i <= 127; ++i) {
				// 	midi.send(0x80, i, 0);
				// }

				break;
			}
			case StrumUp:
			case StrumDown: {
				auto& midi = get_midi_manager();
				midi.send(0xC0, 29);

				for (auto i = Green; i <= Orange; ++i) {
					if ((_frets & (1 << i)) != 0) {
						midi.send(0x90, i + Offset, 127);
					}
				}

				break;
			}
		}
	}

	void GuitarInputDriver::on_button_up(std::size_t index) {
		switch (index) {
			case Green:
			case Red:
			case Yellow:
			case Blue:
			case Orange: {
				_frets &= ~(1 << index);
				break;
			}
		}
	}

	void GuitarInputDriver::on_input_change(InputChangeEvent&&) {

	}
}
