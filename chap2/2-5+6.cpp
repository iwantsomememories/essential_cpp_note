#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename elemType>
elemType Max(elemType a, elemType b){
    if(a > b)
        return a;
    else
        return b;
}

template <typename elemType>
elemType Max(vector<elemType> vec){
    elemType max_value = vec[0];

    for(int i = 1; i < vec.size(); i++){
        if(vec[i] > max_value)
            max_value = vec[i];
    }

    return max_value;
}

template <typename elemType>
elemType Max(elemType arr[], int size){
    elemType max_value = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max_value){
            max_value = arr[i];
        }
    }

    return max_value;
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 9, 2, 3};

    cout << Max(a, 1) << endl;
    return 0;
}

