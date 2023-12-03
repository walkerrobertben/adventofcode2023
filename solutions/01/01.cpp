#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include <map>

static const int CHAR_DIGIT_TO_INT_SHIFT = -48;

static int parseDigit(std::string spelt) {
	std::map<std::string, int> numberMap = {
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"1", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
	};

	return numberMap.find(spelt)->second;
}

static void part1() {
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

		total += (digit0 + CHAR_DIGIT_TO_INT_SHIFT) * 10 + (digit1 + CHAR_DIGIT_TO_INT_SHIFT);
	}

	std::cout << total << std::endl;
}

static void part2() {
	std::ifstream file("solutions/01/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	int total = 0;

	std::regex pattern("(?=(one|two|three|four|five|six|seven|eight|nine|[1-9]))");

	std::string line;
	while (std::getline(file, line)) {
		std::sregex_iterator next(line.begin(), line.end(), pattern);
		std::sregex_iterator end;
		std::string digit0, digit1;

		while (next != end) {
			std::smatch match = *next;
			std::string digit = match.str(1);
			if (digit0.empty()) {
				digit0 = digit;
			}
			digit1 = digit;
			next++;
		}

		total += parseDigit(digit0) * 10 + parseDigit(digit1);
	}

	std::cout << total << std::endl;
}

void solution01() {
	part1();
	part2();
}
