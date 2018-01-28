#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    regex reg1("\\w+day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";

    smatch r1;
    smatch r2;

    cout << boolalpha << regex_match(s1, r1, reg1) << endl;
    cout << boolalpha << regex_match(s2, r2, reg1) << endl;
    cout << "s1 match result: " << r1.str() << endl;
    cout << "s2 match result: " << r2.str() << endl;

    return 0;
}
