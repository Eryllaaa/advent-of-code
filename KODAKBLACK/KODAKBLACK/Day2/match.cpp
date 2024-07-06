#include "match.h";

using namespace std;

ColorMatch::ColorMatch(int red, int green, int blue) {
	colorsMax = new int[3];
	colorsMax[0] = red;
	colorsMax[1] = green;
	colorsMax[2] = blue;
}

ColorMatch::~ColorMatch()
{
	delete[] colorsMax;
}

bool ColorMatch::WithinMax(Colors color, int input) {
	return input < colorsMax[(int)color];
}
