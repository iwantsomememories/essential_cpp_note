#include <iostream>
#include <vector>
using namespace std;

const vector<int>* seq_pent(int);

bool pent_elem(int pos, int& elme);

int main(int argc, char const *argv[])
{
    int size;
    int elem;

    cout << "Please enter the pos of pentagonal elem: ";
    cin >> size;
    
    if(pent_elem(size, elem)){
        cout << "The element is " 
            << elem << endl;
    }

    return 0;
}

inline bool is_size_ok(int size){
    const int maxsize = 1024;
    if(size <= 0 || size > maxsize){
        cerr << "oops! invalid pos: "
            << size << endl;
        return false;
    }
    return true;
}

const vector<int>* seq_pent(int size){
    static vector<int> pent;

    if(!is_size_ok(size)){
        return 0;
    }

    int n = pent.size();

    for(int i = n; i < size; i++){
        int elem = (i+1)*(3*(i+1)-1)/2;
        pent.push_back(elem);
    }

    return &pent;
}

bool pent_elem(int pos, int& elem){
    const vector<int>* vec = seq_pent(pos);
    if(vec == 0){
        elem = 0;
        return false;
    }
    elem = (*vec)[pos-1];
    return true;
}