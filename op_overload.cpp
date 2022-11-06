#include <iostream>
#include <stack>

using namespace std;

class Stack {
    private:
        stack<int> stackk;

    public:
        void push(int x) {
            stackk.push(x);
        }

        void pop() {
            stackk.pop();
        }

        int top() {
            return stackk.top();
        }

        bool empty() {
            return stackk.empty();
        }

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