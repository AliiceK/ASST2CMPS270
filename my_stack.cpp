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
bool Stack<T>::emptystack() const {
    return stackk.empty();
}

template <class T>
T &Stack<T>:: top() {
    return stack.back();
}

template <class T>
void Stack<T>::push(const T &newitem) {
    stackk.push_back(newitem);
}

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