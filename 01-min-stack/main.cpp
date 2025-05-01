#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> dataStack; 
    stack<int> minStack; 
public:
    MinStack() {

    }
    
    void push(int val) {
        dataStack.push(val); 
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val); 
        }else {
            minStack.push(minStack.top()); 
        }
    }
    
    void pop() {
        if (dataStack.empty()) return; 
        int topValue = dataStack.top(); 
        dataStack.pop(); 
        minStack.pop();
    }
    
    int top() {
        return dataStack.top(); 
    }
    
    int getMin() {
        return minStack.top();
    }
};
int main() {
    MinStack minStack;
    minStack.push(2);
    minStack.push(3);
    minStack.push(1); 
    cout << "最小值: " << minStack.getMin() << endl; // Returns 1.
    minStack.pop();
    cout << "栈顶: " << minStack.top() << endl; // Returns 3.
    cout << "最小: " << minStack.getMin() << endl; // Returns 2.
    return 0;
} 