#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

void solution01() {
	part1();
}

void part1() {
	std::ifstream file("solutions/01/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	int total = 0;

	std::string line;
	while (std::getline(file, line)) {
		char digit0 = '\0';
		char digit1;

		for (int i = 0; i < line.size(); i++) {
			char c = line.at(i);
			if (std::isdigit(c)) {
				if (digit0 == '\0') {
					digit0 = c;
				}
				digit1 = c;
			}
		}

		total += (digit0 - 48) * 10 + (digit1 - 48);
	}

	std::cout << total << std::endl;
}

void part2() {

}
