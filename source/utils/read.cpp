#include <iostream>
#include "read.hpp"
#include <string>
#include <string_view>

namespace ghwt_midi::utils {
	std::string read() {
		std::string input;
		std::getline(std::cin, input);
		return input;
	}

	std::string read(std::string_view prompt) {
		std::cout << prompt << ' ';
		return read();
	}
}
