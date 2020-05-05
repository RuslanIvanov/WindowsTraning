#pragma once
#include<string>
#include <random>
#include <chrono>
#include <ratio>
#include <thread>

inline short incShort(short st)
{
    st++;
    return st;
}

inline int makeIntFormStr(std::string  str) 
{
    int r = 0;

   // try 
    {
        r = std::stoi(str);//эта ф. генерит искл, кторые уже попадают в разделяемую область
    }
  //  catch (std::invalid_argument e) { throw "invalid_argument"; }
  //  catch (std::out_of_range e) { throw "out_of_range"; }
  //  catch (...) { throw "undefine exception"; }

    return r;
}

inline void mytask()
{
    using milliseconds = std::chrono::duration<long long, std::milli>;
    milliseconds ms = static_cast<milliseconds>(0);
    char c = std::rand() % 'Z';
    ms = static_cast<milliseconds> (c);
    std::cout << "\nrun task '" << c << "' sleep " << static_cast<int>(c) << " ms\n";
   // std::cout << "\nrun task " << c <<" ms "<< std::chrono::duration <double, std::milli>(ms);
    std::this_thread::sleep_for(ms);
}