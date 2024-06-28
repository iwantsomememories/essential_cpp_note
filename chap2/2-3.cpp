#include <iostream>
#include <vector>
using namespace std;

const vector<int>* seq_pent(int);

void display(const vector<int>&, const string&);

int main(int argc, char const *argv[])
{
    int size;
    cout << "Please enter the size of pentagonal sequence: ";
    cin >> size;
    
    const vector<int>* pent = seq_pent(size);
    if(pent != 0) display(*pent, "Pentagonal");
    return 0;
}

inline bool is_size_ok(int size){
    const int maxsize = 1024;
    if(size <= 0 || size > maxsize){
        cerr << "oops: invalid size: "
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

void display(const vector<int>& vec, const string& seq_type){
    cout << seq_type << " Sequence: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}