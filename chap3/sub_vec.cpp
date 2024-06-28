#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

// 返回指向应该删除的第一个元素的指针/迭代器
template <typename InputIterator, typename ElemType, typename Comp>
InputIterator
sub_vec(InputIterator first, InputIterator last, const ElemType& val, Comp pred){
    
    sort(first, last, pred);

    InputIterator iter = find_if(first, last, not1(bind2nd(pred, val)));
    
    return iter;
}

int main(int argc, char const *argv[])
{
    int arr[8] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> vec(arr, arr+8);
    vector<int> res(vec);

    greater<int> comp;
    int *last = sub_vec(arr, arr+8, 10, comp);

    for (int* pointer = arr; pointer != last; pointer++)
    {
        cout << *pointer << " ";
    }
    cout << endl;

    return 0;
}
