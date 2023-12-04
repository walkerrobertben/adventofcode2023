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

static void doCard(int &cards, std::vector<std::string> &lines, int from) {
	cards += 1;

	int matches = 0;
	bool winners[100] = {};

	for (int i = 10; i < 38; i+=3) {
		winners[std::stoi(lines[from].substr(i, 2))] = true;
	}

	for (int i = 42; i < 115; i+=3) {
		if (winners[std::stoi(lines[from].substr(i, 2))]) {
			matches++;
		}
	}

	for (int i = 0; i < std::min(matches, ((int) lines.size()) - from - 1); i++) {
		doCard(cards, lines, from + i + 1);
	}
}

static void part2() {
	std::ifstream file("solutions/04/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	std::string line;
	std::vector<std::string> lines;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	int count = 0;
	for (int i = 0; i < lines.size(); i++) {
		doCard(count, lines, i);
	}

	std::cout << count << std::endl;
}

void solution04() {
	part1();
	part2();
}
