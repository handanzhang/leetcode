/*
一个数组，找出不在数组内且最挨着的正整数
数组 【1,4,5,3】 为 2，
数组[1,2,3,5]   为 4
*/




#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;




int get_min(std::vector<int> &a)
{
    auto min = a.at(0);
    for(auto i : a)
        if (i < min)
            min = i;
    return min;
}


int get_max(std::vector<int> & a)
{
    auto max = a.at(0);
    for(auto i : a)
        if (i > max)
            max = i;
    return max;
}
int main()
{


    std::vector<int> aa = {1,2,3,4,5,6,15};
    auto min = get_min(aa);
    auto max = get_max(aa);
    std::vector<int> bb( aa.size(), 0);


    for (auto i : aa) // 把差值用数组存起来，有用标1，然后找第一个0
        if ( i - min <= aa.size())
            bb[i - min] = 1;


    for(auto i = 0 ; i<bb.size(); ++i)
    {
        auto k = bb.at(i);
        if (k == 0)
        {
            std::cout<< i + min;
            return 0;
        }
    }
    std::cout<<max + 1;
}