#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "match.h"
#include <cctype>;
#include <string>

using namespace std;

class day2 {
	private:
	
	string filePath = "Day2/puzzle-input-day2.txt";
	ifstream file;
	vector<string> fileText;
	ColorMatch currentMatch;
	bool CheckLine(ColorMatch& match, string& line);

	public:

	day2();
	void Run();
};
