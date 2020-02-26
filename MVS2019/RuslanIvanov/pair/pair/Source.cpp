#include <iostream>
#include <vector>
#include <string>
#include <iterator>


using namespace std;
typedef pair<string, vector<int> > MyWord;


ostream& operator <<(ostream& out, MyWord& word)
{
    out << word.first << " - ";
    copy(word.second.begin(), word.second.end() - 1, ostream_iterator<int>(cout, ", "));
    out << *(word.second.end() - 1);
    return out;
}


int main(int, char**) 
{
    MyWord x;
    cout << x;
}