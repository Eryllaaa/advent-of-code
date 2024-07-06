#include "day2.h";

using namespace std;

day2::day2() 
	: currentMatch(12, 13, 14)
{
	ifstream lfile(filePath);
	string str = "";
	while (lfile >> str) {
		fileText.push_back(str);
	}
	lfile.close();
	cout << "fileText";
}

bool day2::CheckLine(ColorMatch& match, string& line) {
	cout << "fileText";
	int val = 0;
	string buffer = "";
	for (char character : line)
	{
		if (isdigit(character))
		{
			buffer += character;
			string str(1, character);
		}
		else if (isalpha(character))
		{
			if (buffer != "")
			{
				val = stoi(buffer);
				buffer = "";
			}
			switch (character)
			{
			case 'r':
				if (!match.WithinMax(red, val))
				{
					return false;
				}
				break;
			case 'g':
				if (!match.WithinMax(green, val))
				{
					return false;
				}
				break;
			case 'b':
				if (!match.WithinMax(blue, val))
				{
					return false;
				}
				break;
			default:
				break;
			}
		}
		else {
			if (buffer != "")
			{
				val = stoi(buffer);
			}
			buffer = "";
		}
	}
}

void day2::Run() {
	cout << "blabvlacar";
	//cout << CheckLine(currentMatch, "Game 1: 5 red, 1 green, 2 blue; 2 green, 8 blue, 6 red; 8 red, 3 blue, 2 green; 6 red, 1 green, 19 blue; 1 red, 17 blue");
}
