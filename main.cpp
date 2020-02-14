// Ruben Navarro
// 02/14/2020
// Stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>

#define SIZE 8000

class MinStack {
public:

    int topIndex = 0;
    int arr[SIZE];
    bool flag = false;

    std::stack<int> s2;

    // stack constructor
    MinStack() {
        topIndex = -1;
    }

    // pushes an integer to the stack
    void push(int x) {
        arr[++topIndex] = x;

        if (flag && (x <= s2.top())) {
            s2.push(x);
        }

        if (!flag) {
            flag = true;
            s2.push(x);
        }
    }

    // pops the top of the stack
    void pop() {
        if (arr[topIndex] == s2.top()) {
            s2.pop();
        }

        arr[topIndex--];

        if (s2.empty()) {
            flag = false;
        }
    }

    // retruns the top value in the stack
    int top() {
        return arr[topIndex];
    }

    int getMin() {
        return s2.top();
    }
};

int main() {
 MinStack* obj = new MinStack();
 obj->push(-2);
 obj->push(0);
 obj->push(-3);
 std::cout << "Current minimum value in the stack: "<< obj->getMin() << std::endl;
 obj->pop();
 std::cout << "Current top of the stack: "<< obj->top() << std::endl;
 obj->pop();
 std::cout << "After 2 pops, current minimum value in the stack: "<< obj->getMin() << std::endl;
    return 0;
}
