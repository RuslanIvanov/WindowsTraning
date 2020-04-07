#include <iostream>
#include <string>
#include <memory>

int main(int,char**)
{
    std::unique_ptr<std::string> s_p(new std::string("Hello, world!"));
    std::string* s = s_p.get(); 
    std::cout << *s << '\n';
    return 0;
}