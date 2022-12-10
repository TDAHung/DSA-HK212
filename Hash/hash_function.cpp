/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int foldShift(long long key, int addressSize)
{   
    string str = to_string(key);
    int temp = 0, sum = 0;
    string current_str = "";
    for(size_t i = 0; i < str.size();i += addressSize){
        temp = i + addressSize;
        current_str = "";
        for(int j = i; j < temp; j++) current_str += str[j];
        sum += stoi(current_str);
    }
    cout << sum << endl;
    string current_result = to_string(sum);
    string result = "";
    for(size_t i = current_result.size()-2; i < current_result.size(); i++) result += current_result[i];
    return stoi(result);
}

int rotation(long long key, int addressSize)
{   
    int fold = foldShift(key, addressSize);
    string str = to_string(fold);
    int size = str.size();
    char temp = str[0];
    str[0] = str[size-1];
    str[size-1]=temp;
    return stoi(str);
}

long int midSquare(long int seed)
{   
    seed *= seed;
    string str = to_string(seed);
    string str_temp ="";
    int size =str.size();
    if(size >= 6){
        for(int i = size-6; i < size-2;i++) str_temp += str[i];
    }else if(size == 5){
        for(int i = 0; i < size - 1;i++) str_temp += str[i];
    }else {
        for(int i = 0; i < size ; i++) str_temp += str[i];
    }
    return stoi(str_temp);
}

long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}

long int digitExtraction(long int seed,int* extractDigits,int size)
{   
    string str = to_string(seed);
    string str_result = "";
    for(int i = 0 ; i < size; i++){
        str_result += str[extractDigits[i]];
    }
    return stoi(str_result);
}

int main()
{
    int n = 600101;
    int a[]={0,2,5};
    cout << digitExtraction(n,a,3);
    
    return 0;
}





