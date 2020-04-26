#pragma once
template <typename T>
void printTime(T start, T end)
{
    std::cout << "\ntime: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms\n";
}