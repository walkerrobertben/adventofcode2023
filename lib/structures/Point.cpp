#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Point::operator<(const Point& other) const {
	if (x == other.x) {
		return y < other.y;
	}
	
	return x < other.x;
}
