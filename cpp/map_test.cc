#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, int> map__;
	map__.insert(make_pair("a", 4));
	map__.insert(make_pair("x", 10));
	map__.insert(make_pair("y", 11));
	map__.insert(make_pair("z", 4));
	map__.insert(make_pair("b", 6));
	map__.insert(make_pair("h", 4));
	map__.insert(make_pair("o", 4));

	map<string, int>::iterator iter;
	for(iter = map__.begin(); iter != map__.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}

	cout << "--------remove elements of value=4--------" << endl;
	iter = map__.begin();
	while(iter != map__.end()) {
		if (iter->second == 4) {
			map__.erase(iter++);
		} else {
			iter++;
		}
	}

	for(iter = map__.begin(); iter != map__.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}

	//后缀形式i++
	//cont int int::operator++(int)
	//{
	//	int oldValue = *this;
	//	++(*this);
	//	return oldValue;
	//}

	return 0;
}

