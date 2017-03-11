#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "usage: elf file" << endl;
		return -1;
	}

	ifstream ifs(argv[1]);
	if (!ifs.good()) {
		cerr << "open file failed, file: " << argv[1] << endl;
		return -1;
	}

	string line;
	while(getline(ifs, line)) {
		istringstream iss(line);
		string word;
		while(iss >> word) {
			cout << word << endl;
		}
	}

	return 0;
}
