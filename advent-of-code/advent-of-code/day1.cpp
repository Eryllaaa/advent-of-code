#include "day1.h"
using namespace std;

day1::day1(){
	
}

int day1::LineToNumber(string& line){
	smatch match1;
	smatch match2;
	regex_search(line, match1, firstDigitRegex);
	regex_search(line, match2, lastDigitRegex);
	int sum = stoi(match1[0].str() + match2[0].str());
	return sum;
}

void day1::Run(){
	string line;
	ifstream file(filePath);
	int sum = 0;
	if (file.is_open()){
		while (getline(file, line)) {
			sum += LineToNumber(line);
		}
		cout << sum;
	}
}