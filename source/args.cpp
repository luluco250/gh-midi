#include "args.hpp"
#include <cstdint>
#include "utils/print.hpp"
#include <stdexcept>

namespace ghwt_midi {
	constexpr auto Port = "--port";
	constexpr auto Input = "--input";
	constexpr auto ListPorts = "--list-ports";
	constexpr auto ListInputs = "--list-inputs";
	constexpr auto Type = "--type";

	Arguments::Arguments(): _parser("gh-midi") {
		_parser
			.add_argument("-p", Port)
			.scan<'i', int>()
			.default_value(0)
			.validate()
		;
		_parser
			.add_argument("-i", Input)
			.scan<'i', int>()
			.default_value(0)
			.validate()
		;
		_parser
			.add_argument(ListPorts)
			.default_value(false)
			.implicit_value(true)
		;
		_parser
			.add_argument(ListInputs)
			.default_value(false)
			.implicit_value(true)
		;
		_parser
			.add_argument(Type)
			.required()
		;
	}

	void Arguments::parse(int argc, const char* const* argv) {
		_parser.parse_args(argc, argv);
	}

	std::string Arguments::usage() const {
		return _parser.help().str();
	}

	bool Arguments::list_ports() const {
		return _parser.get<bool>(ListPorts);
	}

	bool Arguments::list_inputs() const {
		return _parser.get<bool>(ListInputs);
	}

	int Arguments::port() const {
		return _parser.get<int>(Port);
	}

	int Arguments::input() const {
		return _parser.get<int>(Input);
	}

	std::string Arguments::type() const {
		return _parser.get(Type);
	}
}
