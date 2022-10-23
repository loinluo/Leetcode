#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> QuIn;
    queue<int> QuOut;
    MyStack() {

    }

    void push(int x) {
        QuIn.push(x);
    }

    int pop() {
        int i = QuIn.size();
        i--;
        while (i--) {
            QuOut.push(QuIn.front());
            QuIn.pop();
        }
        int result = QuIn.front();
        QuIn.pop();
        QuIn = QuOut;
        while (!QuOut.empty()) {
            QuOut.pop();
        }
        return result;
    }

    int top() {
        return QuIn.back();
    }

    bool empty() {
        return QuIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */