#include "day3.h";
#include <string>

day3::day3() {
	file.open(filePath);
	BuildSchematic();
}

void day3::BuildSchematic() {
	std::string str = "";
	for (std::string str; getline(file, str);) {
		schematic.push_back(str);
	}
}

bool day3::IsSymbol(const char& input) {
	return !(isdigit(input) || input == '.');
}

bool day3::IsOutOfRange(const int x, const int y, const int maxX, const int maxY) {
	return x > maxX || x < 0 || y > maxY || y < 0;
}

NumCoord day3::GetNumber(const int x, const int y, const int maxX, const int maxY) {
	uint16_t result = 0;
	std::string buffer = "";
	int16_t firstDigitIndex = 0;
	int16_t keepFirstDigitIndex = 0;
	while (!IsOutOfRange(x + firstDigitIndex, y, maxX, maxY) && isdigit(schematic[y][x + firstDigitIndex]))
	{
		firstDigitIndex--;
	}
	keepFirstDigitIndex = firstDigitIndex;
	while (firstDigitIndex <= 0 || isdigit(schematic[y][x + firstDigitIndex]))
	{
		firstDigitIndex++;
		buffer += schematic[y][x + firstDigitIndex];
	}
	result = std::stoi(buffer);
	std::vector<int16_t> coordinates;
	coordinates.push_back(x + keepFirstDigitIndex);
	coordinates.push_back(y);
	return NumCoord(result, coordinates);
}

bool day3::Contains(std::vector<NumCoord> vector, NumCoord input) {
	for (NumCoord val : vector) {
		if (val.coordinates == input.coordinates)
		{
			return true;
		}
	}
	return false;
}

std::uint64_t day3::GetAdjacentSum(const int x, const int y, const int maxX, const int maxY) {
	uint16_t result = 0;
	std::vector<NumCoord> checkedCoordinates;
	NumCoord numcoord;
	for (int yIndex = -1; yIndex <= 1; yIndex++)
	{
		for (int xIndex = -1; xIndex <= 1; xIndex++)
		{
			if (!IsOutOfRange(y + yIndex, x + xIndex, maxX, maxY) && isdigit(schematic[y + yIndex][x + xIndex]))
			{
				if (yIndex == 0 && xIndex == 0)
				{
					continue;
				}
				numcoord = GetNumber(x + xIndex, y + yIndex, maxX, maxY);
				if (Contains(checkedCoordinates, numcoord))
				{
					std::cout << "nope" << std::endl;
					continue;
				}
				checkedCoordinates.push_back(numcoord);
				std::cout << "number: " + std::to_string(numcoord.number) + " at: " + std::to_string(numcoord.coordinates[0]) + ", " + std::to_string(numcoord.coordinates[1]) << std::endl;
				result += numcoord.number;
			}
		}
	}
	return result;
}

void day3::Run() {
	uint16_t length = schematic.size();
	uint16_t Llength;

	for (size_t y = 0; y < length; y++)
	{
		Llength = schematic[y].size();
		for (size_t x = 0; x < Llength; x++) {
			if (IsSymbol(schematic[y][x]))
			{
				result += GetAdjacentSum(x, y, Llength, length);
			}
		}
	}
	std::cout << result;
}
