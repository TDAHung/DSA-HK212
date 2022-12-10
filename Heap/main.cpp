/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class MAX_HEAP{
    private:
        int capacity;
        int count;
        T *elements = new T[capacity + 1];
    public:
        MAX_HEAP(int capacity,int count,T *elements):capacity(capacity),count(count),elements(elements){};
        void push(T data);
        void remove(T data);
        void heapify(int n, int index);
        int  size();
        bool isEmpty();
        T    peek();
        bool contains(T item);
        bool pop();
        void ensureCapacity(int minCapacity);
        void reheapUp(int position){
            if(position < 0 || position >= count || count == 0) return;
            else{
                int parent = (position - 1)/2;
                if(elements[position] > elements[parent]){    
                    swap(elements[position],elements[parent]);
                    reheapUp(parent);
                }
            }
        }
        void reheapDown(int index){
            int leftChild = 2*index + 1;
            int rightChild = 2*index + 2;
            int child, bottom = count - 1;
            if(leftChild <= bottom){
                if(rightChild <= bottom && elements[rightChild] > elements[leftChild]) child = rightChild;
                else child = leftChild;
                
                if(elements[child] > elements[index]){
                    int temp = elements[child];
                    elements[child] = elements[index];
                    elements[index] = temp;
            reheapDown(child);
                }
            }
        }
        int getItem(T data);
        void clear();
        void heapSort(int begin, int end);
        string toString();
};

template <class T>
void MAX_HEAP<T>::push(T data){
    if(count == capacity) return;
    else{
        elements[count] = data;
        count++;
        reheapUp(count-1);
    }
}

template<class T>
int MAX_HEAP<T>::getItem(T data) {
    if(!count) return -1;
    for(int i = 0 ; i< count;i++)
        if(data == elements[i]) return i;
    return -1;
}

template <class T>
void MAX_HEAP<T>::remove(T data){
    if(!count) return;
    int i = getItem(data);
    elements[i] = INT8_MAX;
    reheapUp(i);
    elements[0]=elements[count-1];
    count--;
    reheapDown(0);
}

template<class T>
void MAX_HEAP<T>::clear() {
    if(!count) return;
    while(count){
        elements[0]=elements[count-1];
        count--;
    }
}

template<class T>
void MAX_HEAP<T>::ensureCapacity(int minCapacity){
    capacity += minCapacity;
}

template<class T>
int MAX_HEAP<T>::size(){
    return count;
}

template<class T>
bool MAX_HEAP<T>::isEmpty(){
    if(size() != 0) return false;
    return true;
}

template<class T>
T MAX_HEAP<T>::peek(){
    if(size() != 0) return elements[0];
    return -1;
}

template<class T>
bool MAX_HEAP<T>::contains(T item){
    if(size() != 0) {
        for(int i = 0; i < count; i++){
            if(elements[i] == item) return true;
        }
    }
    return false;
}

template<class T>
bool MAX_HEAP<T>::pop(){
    if(size() == 0) return false;
    else{
        elements[0] = elements[count - 1];
        count--;
        reheapDown(0);
    return 1;
    }
}

template<class T>
void MAX_HEAP<T>::heapify(int n, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2; 
    if(left > n && elements[left] > elements[largest])
        largest = left;
    if (right < n && elements[right] > elements[largest])
        largest = right;
    if(largest != index){
        swap(elements[largest],elements[index]);
        heapify(n,largest);
    }
}

template<class T>
void MAX_HEAP<T>::heapSort(int begin, int end){
    for(int i = count/2 - 1 ; i >= 0; i--){
        heapify(count,i);
    }
    
    for (int i = count - 1; i > 0; i--) {
        swap(elements[0], elements[i]);
        heapify(i, 0);
    }
}

template<class T>
string MAX_HEAP<T>::toString(){
    stringstream ss;
    for(int i = 0 ; i < count; i++)
    ss << elements[i] << " ";
    return ss.str();
}

int main()
{   
    int capacity = 20;
    int arr[]={-2,5,4,6,10,-6,11,-5,3,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    MAX_HEAP<int> *heap = new MAX_HEAP<int>(20,n,arr);
    cout << heap->toString()<<endl;
    cout << heap->toString()<<endl;
    return 0;
}
