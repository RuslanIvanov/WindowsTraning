#pragma once
#include<string>
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