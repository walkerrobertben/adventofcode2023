#include "main.h"
#include <cstdlib>

void (*solutions[])(void) = {
    solution01,
	solution02,
};

int main(int argc, char* argv[]) {
	solutions[std::atoi(argv[1]) - 1]();
	return 0;
}
