#include <iostream>

#include <cstring>
using namespace std;
template <class T>
class stack {
public:
    class Node;
private:
    Node* head = NULL;
    Node* tail = NULL;
    int count = 0;
public:
    void pop();
    void push(T c);
    T top();
    bool isEmpty();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class stack<T>;
    public:
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
        Node(){
        next =NULL;
        }
    };
};

template <class T>
void stack<T>::push(T c) {
    if (count == 0) {
       head = new Node(c,NULL);
       tail=head;
   }
   else{
       tail->next=new Node(c,NULL);
       tail=tail->next;
   }
    count++;
}

template <class T>
void stack<T>::pop() {
    if (head) {
        Node* phead = this->head;
        while (phead->next->next != NULL) {
            phead = phead->next;
        }
        Node* ptail = this->tail;
        tail = phead;
        delete (ptail);
    }
    else throw;
}


template <class T>
T stack <T>::top() {
    if (!head) throw;
    return head->data;
}

template <class T>
bool stack <T>::isEmpty() {
    if (count == 0) return 1;
    return 0;
}

int main() {
    stack<int> Sta;
    Sta.push(1);
    Sta.push(2);
    Sta.push(-2);
    cout << Sta.top()<<endl;
    Sta.pop();
    cout << Sta.top();
    return 0;
}







