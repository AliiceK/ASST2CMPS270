#include <iostream>
#include <stack>

using namespace std;

class Stack {
    private:
        stack<int> stackk;

    public:
        // the function push() will take a new value as a paramter and returns the stack with this new item
        void push(int x) {
            stackk.push(x);
        }

        // the function pop() takes no parameters and will pop the item at the top of the stack
        void pop() {
            stackk.pop();
        }

        // the function top() will take no paramters and will return the value at the top of the stack
        int top() {
            return stackk.top();
        }
        
        // the function empty() will take no parameters and will return true or false depending whether the stack is empty or not
        bool empty() {
            return stackk.empty();
        }

        // the function operator+() will take as parameters another stack and will return a new stack
        Stack operator+ (Stack &b) {
            Stack temporarystack;
            while (!stackk.empty()) {
                temporarystack.push(stackk.top());
                stackk.pop();
            }

            while (!b.empty()) {
                temporarystack.push(b.top());
                b.pop();
            }
            
            return temporarystack;
        }
};

int main() {
    Stack s1, s2;

    s1.push(6);
    s1.push(4);
    s1.push(9);
    s1.push(8);
    Stack s3 = s1 + s2;

    while (!s3.empty()) {
        cout << s3.top() << endl;
        s3.pop();

    }
    return 0;
}