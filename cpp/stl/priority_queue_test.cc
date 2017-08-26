#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void output(priority_queue<int>& q) {
    while(!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}

int main() {
    priority_queue<int> _queue;

    for(int i = 0; i < 9; i++) {
        _queue.push(i);
    }

    output(_queue);
    
    cout << "***" << endl;

    for(int i = 9; i > 0; --i) {
        _queue.push(i);
    }
    _queue.push(19);

    output(_queue);


    return 0;
}
