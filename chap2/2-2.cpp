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

const vector<int>* seq_pent(int length){
    static vector<int> pent;
    const int maxsize = 1024;

    if(length <= 0 || length > maxsize){
        cerr << "oops: invalid size: "
            << length << endl;
        return 0;
    }
    int n = pent.size();

    for(int i = n; i < length; i++){
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