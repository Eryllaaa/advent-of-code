#pragma once

using namespace std;

enum Colors { red = 1, green, blue };

class ColorMatch {
public:
	ColorMatch(int red, int green, int blue);
	~ColorMatch();
	int* colorsMax;
	bool WithinMax(Colors color, int input);
};

