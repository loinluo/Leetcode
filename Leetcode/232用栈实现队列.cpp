#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. �Ӷ��п�ͷ�Ƴ���������Ԫ��*/
    int pop() {
        // ֻ�е�stOutΪ�յ�ʱ���ٴ�stIn�ﵼ�����ݣ�����stInȫ�����ݣ�
        if (stOut.empty()) {
            // ��stIn��������ֱ��stInΪ��
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        //while (!stOut.empty()) {
        //    stIn.push(stOut.top());
        //    stOut.pop();
        //}
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // ֱ��ʹ�����е�pop����
        stOut.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//int main() {
//    MyQueue* obj = new MyQueue();
//    obj->push(1);
//    obj->push(2);
//    int param_3 = obj->peek();
//    cout << param_3 << endl;
//    int param_2 = obj->pop();
//    cout << param_2 << endl;
//    bool param_4 = obj->empty();
//    cout << param_4 << endl;
//}