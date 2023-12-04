#include <fstream>
#include <iostream>
#include <string>

static void part1() {
	std::ifstream file("solutions/04/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	int score = 0;

	std::string line;
	while (std::getline(file, line)) {
		int matches = 0;
		bool winners[100] = {};

		for (int i = 10; i < 38; i+=3) {
			winners[std::stoi(line.substr(i, 2))] = true;
		}

		for (int i = 42; i < 115; i+=3) {
			if (winners[std::stoi(line.substr(i, 2))]) {
				matches++;
			}
		}

		score += (int) pow(2, matches - 1);
	}
	
	std::cout << score << std::endl;
}



static void part2() {
	std::ifstream file("solutions/04/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

}


void solution04() {
	part1();
	part2();
}
