#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <ctime>

using namespace std;

vector<string> split(string &str, char delimiter);

int main()
{
	clock_t start, end;
	double result;

	start = clock();
	string file_path = "";
	ifstream file(file_path);
	if (file.fail()) return (cout << "File Read Fail!!" << endl) && 0;

	vector<string> time;
	vector<string> location;
	vector<string> voltage;
	vector<string> temp;

	string in_line;

	printf("CSV File Parsing Start...\n");
	while (getline(file,in_line))
	{
		temp = split(in_line, ',');
		time.push_back(temp[0]);
		time.push_back(temp[2]);
		time.push_back(temp[4]);
	}
	end = clock();
	printf("CSV File Parsing End...\n");

	result = (double)(end - start);

	printf("%fms", result);

	file.close();

	return 0;
}

vector<string> split(string &str, char delimiter) {

	vector<string> t;
	int s = 0, e = str.find(delimiter);

	while (e != string::npos) {
		t.push_back(str.substr(s, e - s));
		s = e + 1;

		e = str.find(delimiter, s);

	}

	t.push_back(str.substr(s));

	return t;
}
