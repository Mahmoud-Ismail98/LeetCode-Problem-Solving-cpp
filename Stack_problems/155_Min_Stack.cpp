#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s; // Stack to store the elements
    stack<int> min_s; // Stack to store the minimum elements

public:
    MinStack() {}

    void push(int val) {
        s.push(val); // Push the value onto the main stack
        if (min_s.empty() || val <= min_s.top()) { // If the minimum stack is empty or the new value is less than or equal to the top of the minimum stack
            min_s.push(val); // Push the value onto the minimum stack
        }
    }

    void pop() {
        if (s.top() == min_s.top()) { // If the top element of the main stack is also the top element of the minimum stack
            min_s.pop(); // Pop the top element from the minimum stack
        }
        s.pop(); // Pop the top element from the main stack
    }

    int top() {
        return s.top(); // Return the top element of the main stack
    }

    int getMin() {
        return min_s.top(); // Return the top element of the minimum stack
    }
};

int main() {
    // Test case
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // Output: -3
    obj->pop();
    cout << obj->top() << endl; // Output: 0
    cout << obj->getMin() << endl; // Output: -2
    delete obj;
    return 0;
}
