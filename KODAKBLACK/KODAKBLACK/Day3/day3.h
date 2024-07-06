#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "NumCoord.cpp";

class day3 {
	private:
		std::string filePath = "Day3/puzzle-input.txt";
		std::ifstream file;
		std::string fileText = "";
		std::vector<std::string> schematic;
		std::uint64_t result = 0;

		void BuildSchematic();
		bool IsSymbol(const char& input);
		bool IsOutOfRange(const int x, const int y, const int maxX, const int maxY);
		bool Contains(std::vector<NumCoord> vector, NumCoord input);
		NumCoord GetNumber(const int x, const int y, const int maxX, const int maxY);
		std::uint64_t GetAdjacentSum(const int x, const int y, const int maxX, const int maxY);

	public:
		void Run();
		day3();
		//~day3();
};