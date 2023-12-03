#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

static const std::string CUBES[3] = {"red", "green", "blue"};

static int getId(std::string game) {
	std::regex pattern("Game ([0-9]+):");
	std::smatch match;
	std::regex_search(game, match, pattern);
	return std::stoi(match[1].str());
}

static std::vector<std::string> getRounds(std::string game) {
	std::string round;
	std::vector<std::string> rounds;

	std::stringstream stream(game.substr(game.find(":") + 1));
	
	while (std::getline(stream, round, ';')) {
		rounds.push_back(round);
	}

	return rounds;
}

static void getCubes(std::string round, int cubes[3]) {
	std::smatch match;

	for (int i = 0; i < 3; i++) {
		std::regex pattern("([0-9]+) " + CUBES[i]);
		if (std::regex_search(round, match, pattern)) {
			cubes[i] = std::stoi(match[1].str());
		};
	}
}

static void part1() {
	std::ifstream file("solutions/02/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	std::string line;

	int total = 0;

	while (std::getline(file, line)) {
		int id = getId(line);
		bool possible = true;

		std::vector<std::string> rounds = getRounds(line);

		for (int i = 0; i < rounds.size(); i++) {

			int cubes[3] = {0, 0, 0};
			getCubes(rounds[i], cubes);

			if (
				cubes[0] > 12 ||
				cubes[1] > 13 ||
				cubes[2] > 14
			) {
				possible = false;
				break;
			}
		}

		if (possible) {
			total += id;
		}
	}

	std::cout << total << std::endl;
}

static void part2() {

}

void solution02() {
	part1();
	part2();
}
