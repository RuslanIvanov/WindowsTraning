#include <iostream>
#include <vector>
#include <string>
#include <iterator>


using namespace std;
typedef pair< string, vector<int> > MyWord;

template <typename T, typename TT>
ostream& operator <<(ostream& out, pair<T, TT>& p)
{
    out << p.first << ": ";

    for (typename TT::iterator i = p.second.begin() ; i != p.second.end();++i)
        out <<*i << ": ";
    return out;
}

//ostream& operator <<(ostream& out, MyWord& word)
//{
//    out << word.first << ": ";
//  
//    for(size_t i = 0 ;i< word.second.size();i++)
//     out << word.second[i]<<", ";
//    return out;
//}


int main(int, char**) 
{
    MyWord x[3]; vector<int> v = { 1,2,3 };
    x[0] = make_pair("aa", v);
    x[1] = make_pair("aaa", v);
    x[2] = make_pair("aaaa", v);
    cout << x[0]<<endl;
    cout << x[1]<< endl;
    cout << x[2] << endl;
}