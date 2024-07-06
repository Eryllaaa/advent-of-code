#include <iostream>
#include <vector>

struct NumCoord {
	uint16_t number;
	std::vector<int16_t> coordinates;

	NumCoord(uint16_t number = NULL, std::vector<int16_t> coordinates = std::vector<int16_t>(NULL)) {
		this->number = number;
		this->coordinates = coordinates;
	}
};