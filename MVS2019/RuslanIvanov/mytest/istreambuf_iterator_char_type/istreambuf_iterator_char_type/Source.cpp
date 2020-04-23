// istreambuf_iterator_char_type.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;

    typedef istreambuf_iterator<char>::char_type CHT1;
    typedef istreambuf_iterator<char>::traits_type CHTR1;

    cout << "(Try the example: 'So many dots to be done'\n"
        << " then an Enter key to insert into the output,\n"
        << " & use a ctrl-Z Enter key combination to exit): ";

    // istreambuf_iterator for input stream
    istreambuf_iterator< CHT1, CHTR1> charInBuf(cin);
    ostreambuf_iterator<char> charOut(cout);

    // Used in conjunction with replace_copy algorithm
    // to insert into output stream and replace spaces
    // with dot-separators
    replace_copy(charInBuf, istreambuf_iterator<char>(),
        charOut, ' ', '.');
}