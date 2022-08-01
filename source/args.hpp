#ifndef GHWT_MIDI_ARGS_HPP
#define GHWT_MIDI_ARGS_HPP

#include <argparse/argparse.hpp>

namespace ghwt_midi {
	class Arguments {
	private:
		argparse::ArgumentParser _parser;

	public:
		Arguments();
		void parse(int argc, const char* const* argv);
		std::string usage() const;
		bool list_ports() const;
		bool list_inputs() const;
		int port() const;
		int input() const;
		std::string type() const;
	};
}

#endif
