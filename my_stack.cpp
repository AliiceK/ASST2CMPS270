#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack {
public:
    bool emptystack() const;
    void pop();
    void push(const T &newitem);
    T &top();
private:
    vector<T> stackk;
};

template <class T>
// the fucntion emptystack() takes no paramters and returns a boolean indicating if the stack is empty or not
bool Stack<T>::emptystack() const {
    return stackk.empty();
}

template <class T>
// the function top() takes no paramters and returns what is at the top of the stack
T &Stack<T>:: top() {
    return stack.back();
}

// the function push will take as a paramter an item to be pushed and will return the stack with this new item
template <class T>
void Stack<T>::push(const T &newitem) {
    stackk.push_back(newitem);
}

// the function pop takes no paramters and returns the stack without the item
template <class T>
void Stack<T>::pop() {
    if (!empty()) {
        stack.pop_back();
    }
}

int main() {
    Stack<int> stckk;
    stckk.push(8);
    stckk.push(9);
    stckk.push(6);
    stckk.push(5);
    while (!stckk.emptystack()) {
        cout<<stckk.top()<< endl;
        stckk.pop();
    }

    return 0;
}