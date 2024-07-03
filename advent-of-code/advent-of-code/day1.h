#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

class day1 {
	private:
		string filePath = "calibration-document.txt";
		regex firstDigitRegex = regex("\\d");
		regex lastDigitRegex = regex("\\d(?!.*\\d)");
		int LineToNumber(string& line);
	public:
		day1();
		void Run();
};
