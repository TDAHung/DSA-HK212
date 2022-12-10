/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{   
     if (right >= left) {
        int pivot = left + (right - left)/ 2;
        cout << "We traverse on index: "<<pivot<<endl;
        if (arr[pivot] == x) return pivot;
        if (arr[pivot] > x) 
            return binarySearch(arr, left, pivot - 1, x);
        else 
            return binarySearch(arr, pivot + 1, right, x);
    }
 
    return -1;
}

int jumpSearch(int arr[], int x, int n) {
    int count = sqrt(n);
    int begin,end;
    for(int i = 0 ; i < n; i+=count){
        cout << i <<" ";
        if(arr[i] == x) return i; 
        else if(arr[i] > x){
            end = i;
            break;
        }
        begin = i;
    }
    
    if(end >= n) end = n; 
    if(end % count == 0) end--;
    
    for(begin++;begin <= end; begin++){
                cout << begin<< " ";
                if(arr[begin] == x) return begin;
            }
    return -1;
}

int interpolationSearch(int arr[], int left, int right, int x)
{   
    int index = -1;
    if (left <= right && x >= arr[left] && x <= arr[right])
    {
        index = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
        cout << "We traverse on index: " << index << endl;
        if (arr[index] == x) return index;
        if (arr[index] < x) return interpolationSearch(arr, index + 1, right, x);
        if (arr[index] > x) return interpolationSearch(arr, left, index - 1, x);
    }
    return index;
}

int main()
{
    int arr[] = { -6,-5,-3,-1,2,3,5,7,9,12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int result = interpolationSearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
    return 0;
}






