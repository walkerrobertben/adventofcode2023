#include <fstream>
#include <iostream>
#include <string>

static bool isSymbol(char c) {
	return !std::isdigit(c) && c != '.';
}

static void part1() {
	std::ifstream file("solutions/03/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	int width = 0;
	int height = 0;
	std::string line;
	std::vector<std::string> lines;
	while (std::getline(file, line)) {
		width = std::max(width, (int) line.length());
		height += 1;
		lines.push_back(line);
	}

	int total = 0;

	std::string value = "";
	bool isPartNumber = false;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			char c = lines[y].at(x);
			bool isDigit = std::isdigit(c);

			// read last digit
			if (!value.empty() && ((x == 0 && y > 0) || !isDigit)) {
				if (isPartNumber) {
					total += std::stoi(value);
				}

				value.clear();
				isPartNumber = false;
			}

			// reading digit
			if (isDigit) {
				value.push_back(c);

				// check around this digit for symbols
				if (!isPartNumber) {
					for (int ox = -1; ox <= 1; ox++) {
						for (int oy = -1; oy <= 1; oy++) {
							if (ox == 0 && oy == 0) continue;

							int ax = x + ox;
							int ay = y + oy;

							if (ax >= 0 && ax < width && ay >= 0 && ay < height) {
								
								char ac = lines[ay].at(ax);
								if (isSymbol(ac)) {
									isPartNumber = true;
								}
							}
						}
					}
				}
			}
		}
	}

	// edge case: if the last char was the last number, count it
	if (isPartNumber) {
		total += std::stoi(value);
	}

	std::cout << total << std::endl;
}

static void part2() {
	std::ifstream file("solutions/03/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}
}


void solution03() {
	part1();
	part2();
}
