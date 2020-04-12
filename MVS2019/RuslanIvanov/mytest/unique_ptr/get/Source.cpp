#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <set>
#include<algorithm>
#include <string>
#include <iterator>
#include <type_traits>
template<typename T>
void mfunc()
{
    std::list<std::shared_ptr<T>> list ;
    // Add stuff to list
    list.sort([](const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs)
        {
            return (*lhs.get() < *rhs.get());
        });
}

int main(int,char**)
{
    std::unique_ptr<std::string> s_p(new std::string("Hello, world!"));
    std::string* s = s_p.get(); 
    std::cout << *s << '\n';

    mfunc<int>();

    std::set<std::shared_ptr<std::string>> sp;
    std::sort(sp.begin(), sp.end(), [](const std::shared_ptr<std::string>& l, const std::shared_ptr<std::string>& r)
        {
            return (*l.get() > * r.get());
            //	return (*l->begin() > *r->begin());
        }
    );

    return 0;
}