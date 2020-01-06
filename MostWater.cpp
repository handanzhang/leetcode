/**
 *Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai)
 . n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
    Output: 49
 */

/*
 思路： 暴力遍历法
  双指针 法
    We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines.
    Futher, we maintain a variable maxarea to store the maximum area obtained till now.
    At every step, we find out the area formed between them, update maxarea and move the pointer pointing to the shorter line towards the other end by one step.

    头尾2个指针，小的向大的方向移动， 以此计算面积，求出最大

*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxAreaBrush(vector<int>& height)
{

    auto maxRet = 0;
    for (int i=0; i < height.size()-1; ++i)
    {
        for(auto j = i+1; j < height.size(); ++j)
        {
            auto s = (j-i) *(height[j] < height[i]? height[j]: height[i]);
            if (s > maxRet)
                maxRet = s;
        }
    }
    return maxRet;
}

int maxAreaTwoPointer(vector<int>& height)
{

    auto maxRet = 0;
    int i = 0, j = height.size() -1;
    while( i != j)
    {
        maxRet = max(maxRet, min(height[i], height[j]) * (j - i)) ;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxRet;
}

int main()
{
    vector<int> tmp =  {1,8,6,2,5,4,8,3,7};
    cout<< maxAreaTwoPointer(tmp);
}