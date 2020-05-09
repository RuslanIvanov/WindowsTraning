#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class vStack
{
public:
    void push(int);
    bool pop(int&);
    unsigned count();
    bool display();
    bool save(const std::string&);
    bool load(const std::string&);
private:
    bool fromStream(std::istream& strm);
    bool toStream(std::ostream&);
    std::vector<int> data_;
};

void vStack::push(int val)
{
    data_.push_back(val);
}

bool vStack::pop(int& val)
{
    if (data_.size())
    {
        val = data_[0];
        data_.erase(data_.begin() + 0);
        return true;
    }
    return false;
}

unsigned vStack::count()
{
    return data_.size();
}

bool vStack::toStream(std::ostream& strm)
{
    for (unsigned pos = 0; pos < data_.size(); pos++)
    {
        strm << data_[pos] << std::endl;
        if (!strm) return true;//break;
    }
    return false;//strm;
}

bool vStack::fromStream(std::istream& strm)
{
    data_.clear();
    while (true)
    {
        int val = 0;
        strm >> val;
        if (strm)
        {
            data_.push_back(val);
        }
        else
        {
            break;
        }
    }
    return (data_.size() > 0 && strm.eof());
}

bool vStack::display()
{
    return toStream(std::cout);
}

bool vStack::save(const std::string& f_name)
{
    std::ofstream out_file(f_name.c_str());
    return toStream(out_file);
}
bool vStack::load(const std::string& f_name)
{
    std::ifstream in_file(f_name.c_str());
    return fromStream(in_file);
}

int main()
{
    int cnt = 0;
    std::cout << "Enter size\n";
    std::cin >> cnt;
    if (cnt > 0)
    {
        vStack stack;
        for (int nom = 0; nom < cnt; nom++)
        {
            std::cout << "Enter element " << nom << "\n";
            int elem = 0;
            std::cin >> elem;
            stack.push(elem);
        }
        std::cout << "\n" << " stack size " << stack.count();
        std::cout << "\n";
        stack.display();
        std::cout << "\n";

        int pop_val = 0;
        if (stack.pop(pop_val))
        {
            std::cout << "value " << pop_val << "\n";
        }

        std::cout << "\n" << " stack size " << stack.count();
        std::cout << "\n";
        stack.display();
        std::cout << "\n";
        std::cout << "Enter file_name\n";
        std::string f_name;
        std::cin >> f_name;
        if (!stack.save(f_name))
        {
            std::cout << "Save failed\n";
        }
        vStack loaded_stack;
        std::cout << "\n";
        std::cout << "Enter file_name\n";
        std::cin >> f_name;
        if (loaded_stack.load(f_name))
        {
            std::cout << "\n" << " stack size " << loaded_stack.count();
            std::cout << "\n";
            loaded_stack.display();
        }
        else
        {
            std::cout << "Load failed\n";
        }


    }
    return 0;
}