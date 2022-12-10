/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int partition(int *a, int left, int right){
    int pivot = a[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[right]);
    return i;
}

void quicksort(int *a, int left, int right){
    if(left >= right) return;
    int p = partition(a,left,right);
    quicksort(a,left,p-1);
    quicksort(a,p+1,right);
}

int partition2(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])i++;
        while (pivot < arr[j])j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
 
void quicksortHolo(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition2(arr, low, high);
        quicksortHolo(arr, low, pivot - 1);
        quicksortHolo(arr, pivot + 1, high);
    }
}

void bubbleSort(int *arr,int n){
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int *arr, int n){
    int index;
    for(int i = 0 ; i < n; i++){
        index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[index] > arr[j]) index = j;
        }
        swap(arr[index],arr[i]);
    }
}

void intertionSort(int *arr, int n){
    int key,j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while( j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int a[10] = {-1,5,6,4,8,2,-6,4,-5,-2};
    bubbleSort(a,10);
    for(int i = 0 ; i < 10;i++){
        cout << a[i]<<" ";
    }

    return 0;
}
