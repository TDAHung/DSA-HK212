#include <iostream>
#include <string>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node;
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList():head(NULL),tail(NULL),count(0){};
    ~DLinkedList();
    void    add(const T &e);                /* Insert an element into the end of the list. */
    void    add(int index, const T &e);     /* Insert an element into the list at given index. */
    int     size();                         /* Return the length (size) of list */
    bool    isEmpty();                      /* Check if the list is empty or not. */
    T       get(int index);                 /* Give the data of the element at given index in the list. */
    void    set(int index, const T &e);     /* Assign new value for element at given index in the list */
    int     indexOf(const T &item);         /* Return the first index wheter item appears in list, otherwise return -1 */
    bool    contains(const T &item);        /* Check if item appears in the list */
    T       removeAt(int index);            /* Remove element at index and return removed value */
    bool    removeItem(const T &item);      /* Remove the first apperance of item in list and return true, otherwise return false */
    void    clear();                        /* Remove all elements in list */
    string  toString();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
   if(count == 0) {
        head=new Node(e);
        tail=head;
    }
    else{
        Node *p= new Node(e);
        tail->next=p;
        p->previous = tail;
        tail=p;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    if (index<0 || index > count) throw "Out of range";
    Node * node = new Node(e);
    if(count == 0){
        head=new Node(e);
        tail=head;
    }else{
        if (index == 0) {
            node->next=head;
            head->previous=node;
            head=node;
        }else if (index == count) {
            node->previous = tail;
            tail->next = node;
            tail = node;
        }else{
            Node * phead = this->head;
            for(int i = 0 ; i < index - 1;i++){
            phead = phead->next;
            }
            Node *temp = phead->next;
            node->next = temp;
            node->previous = phead;
            phead->next = node;
            temp->previous = node;
        }
    }
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    return count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    if(index < 0 || index >= count) throw "Out of range";
    Node *phead = this->head;
    for(int i = 0;i < index;i++){
        phead=phead->next;
    }
    return phead->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    if(index < 0 || index >= count) throw "Out of range";
    Node *phead=this->head;
    for(int i = 0;i < index;i++){
        phead=phead->next;
    }
    phead->data=e;
}

template<class T>
bool DLinkedList<T>::isEmpty() {
    return count==0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    Node *phead=this->head;
    for(int i = 0; i< count ;i++){
        if(phead->data==item) return i;
        else phead=phead->next;
    }
    return -1;
    
    
}

template<class T>
bool DLinkedList<T>::contains(const T& item){
    return indexOf(item) != -1;
}

template <class T>
T DLinkedList<T>::removeAt(int index){
    if (index < 0 || index >= count || count == 0) throw "Out of range";
    T value;
    
    if (index == 0) {
        if (count == 1) {
            value = head->data;
            delete (head);
        }else{
            Node * phead = this->head;
            value = phead->data;
            head = phead->next;
            delete (phead);
        }
    }
    
    else if (index == count - 1) {
        Node * ptail = tail;
        value = ptail->data;
        tail = ptail->previous;
        delete (ptail);
    }
    
    else {
        Node *phead = this->head;
        for(int i = 0; i < index - 1; i++) {
            phead = phead->next;
        }
        Node *temp = phead->next;
        value = temp->data;
        phead->next = temp->next;
        temp->next->previous = phead;
        delete (temp);
    }
    count--;
    return value;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item){
    Node *phead = this->head;
    for(int i = 0;i < count;i++){
        if(phead->data == item){
        removeAt(i);
        return 1;
    }
    phead = phead->next;
    }
    return 0;
}

template<class T>
void DLinkedList<T>::clear(){
    Node *phead = this->head;
    while(phead!=NULL){
        phead = phead->next;
        delete(phead);
    }
    this->head = NULL;
    this->tail = NULL;
    count = 0;
}

template<class T>
string DLinkedList<T>::toString(){
    Node * phead = this->head;
    string res = "";
    while (phead) {
    res = res + to_string(phead->data) + " ";
    phead = phead -> next;
    }
return res;
}


int main()
{
    DLinkedList<int> *ll = new DLinkedList<int>();
    ll->add(-2);
    ll->add(-1);
    ll->add(5);
    ll->add(4);
    cout << ll->toString()<<endl;
    ll->add(4,3);
    cout << ll->toString()<<endl;
    ll->removeAt(2);
    cout << ll->toString()<<endl;
    return 0;
}


