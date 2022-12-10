#include <iostream>

#include <cstring>
using namespace std;
template <class T>
class queue {
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
        friend class queue<T>;
    public:
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void queue<T>::push(T c) {
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
void queue<T>::pop() {
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
T queue <T>::top() {
    if (!head) throw;
    return head->data;
}

template <class T>
bool queue <T>::isEmpty() {
    if (count == 0) return 1;
    return 0;
}

int main() {
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(-2);
    cout << que.top()<<endl;
    que.pop();
    cout << que.top();
    return 0;
}






