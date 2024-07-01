#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please enter a number: \n";
    istream_iterator<int> in_num(cin);
    istream_iterator<int> eof;
    ofstream out_odd("output_odd.txt");
    ofstream out_even("output_even.txt");
    if (!out_odd || !out_even)
    {
        cerr << "unable to open the necessary files.\n";
        exit(-1);
    }
    ostream_iterator<int> oo(out_odd, " ");
    ostream_iterator<int> oe(out_even, "\n");
    
    int num;
    while (in_num != eof)
    {
        num = *in_num;
        if (num%2 == 1)
        {
            *oo = num;
            oo++;
        } else
        {
            *oe = num;
            oe++;
        }
        cout << "Please enter a number: \n";
        in_num++;    
    }
    return 0;
}
