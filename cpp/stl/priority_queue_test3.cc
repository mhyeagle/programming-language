#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node {
    int x, y;
    Node(int a = 0, int b = 0):
        x(a), y(b) {}
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.x < b.x;
    }
};

int main() {
    priority_queue<Node, vector<Node>, cmp> q;

    for(int i = 0; i < 10; ++i)
        q.push(Node(rand(), rand()));
    
    while(!q.empty()) {
        cout << q.top().x << " " << q.top().y << endl;
        q.pop();
    }

    return 0;
}
