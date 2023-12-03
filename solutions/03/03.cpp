#include <fstream>
#include <iostream>
#include <string>
#include <map>

struct XY {
	int x, y;

	XY (int _x, int _y) {
		x = _x;
		y = _y;
	}

	bool operator<(const XY& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

static bool isSymbol(char c) {
	return !std::isdigit(c) && c != '.';
}

static std::vector<std::string> getEngine(int &width, int &height) {
	std::ifstream file("solutions/03/data");

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}

	std::string line;
	std::vector<std::string> lines;
	while (std::getline(file, line)) {
		width = std::max(width, (int) line.length());
		height += 1;
		lines.push_back(line);
	}

	return lines;
}

static void part1() {
	int width, height = 0;
	std::vector<std::string> engine = getEngine(width, height);

	int total = 0;

	std::string value = "";
	bool isPartNumber = false;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			char c = engine[y].at(x);
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
								
								char ac = engine[ay].at(ax);
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
	int width, height = 0;
	std::vector<std::string> engine = getEngine(width, height);

	long total = 0;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			char c = engine[y].at(x);
			if (c == '*') {

				std::map<XY, int> adjacent;

				for (int ox = -1; ox <= 1; ox++) {
					for (int oy = -1; oy <= 1; oy++) {
						if (ox == 0 && oy == 0) continue;

						int ax = x + ox;
						int ay = y + oy;

						char n = engine[ay].at(ax);
						if (isdigit(n)) {

							int i0 = ax;
							while (i0 > 0 && std::isdigit(engine[ay].at(i0 - 1))) {
								i0--;
							}

							XY number = XY(i0, ay);
							if (adjacent.find(number) == adjacent.end()) {

								int i1 = ax;
								while (i1 < width - 1 && std::isdigit(engine[ay].at(i1 + 1))) {
									i1++;
								}

								adjacent[number] = std::stoi(engine[ay].substr(i0, 1 + i1 - i0));
							}
						}
					}
				}

				if (adjacent.size() == 2) {
					std::map<XY, int>::iterator iter = adjacent.begin();
					total += iter++->second * iter->second;
				}
			}
		}
	}

	std::cout << total << std::endl;
}


void solution03() {
	part1();
	part2();
}
