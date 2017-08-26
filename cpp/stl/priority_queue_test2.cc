#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class MyResult {
public:
    MyResult(string str, int age, int money) 
        :__name(str), __age(age), __money(money) {
    }

    string get_name() {
        return __name;
    }

    int get_age() {
        return __age;
    }

    int get_money() {
        return __money;
    }

private:
    string __name;
    int __age;
    int __money;
};

class MyCompare {
public:
    bool operator() (MyResult& lp, MyResult& rp) {
        if (lp.get_age() == rp.get_age())
            return lp.get_money() < rp.get_money();
        return lp.get_age() > rp.get_age();
    }
};

int main() {
    priority_queue<MyResult, vector<MyResult>, MyCompare> result_queue;

    MyResult r1("miao", 29, 1000), r2("guan", 28, 100), r3("wu", 27, 10);
    result_queue.push(r1);
    result_queue.push(r2);
    result_queue.push(r3);

    while(!result_queue.empty()) {
        MyResult tmp = result_queue.top();
        cout << tmp.get_name() << endl;
        result_queue.pop();
    }

    return 0;
}
