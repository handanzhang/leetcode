/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


解法：没啥可以注释的，用循环来解，不要用递归之类的，防止爆栈，毕竟数量成长的极其快，指数级成长

*/


#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;

        map<int, vector<char>> t = {
                {2, {'a', 'b', 'c'}},
                {3, {'d', 'e', 'f'}},
                {4, {'g', 'h', 'i'}},
                {5, {'j', 'k', 'l'}},
                {6, {'m', 'n', 'o'}},
                {7, {'p', 'q', 'r', 's'}},
                {8, {'t', 'u', 'v'}},
                {9, {'w', 'x', 'y', 'z'}}
        };
        vector<vector<char>> chars;
        for (char c : digits)
        {
            int i = int(c) - int('0');
            if (t.find(i) != t.end())
                chars.push_back(t[i]);
        }

        vector<int> digit_index(chars.size(), 0); // 唯一要点，记录每一个vector的偏移

        int ll = chars.size();
        while(true)
        {
            string ss = "";
            for(auto i=ll-1; i>=0; --i)
            {
                if (digit_index[0] >= chars[0].size()) // 直接return是因为有坏的字符串
                    return ret; 

                if(i != 0 && digit_index[i] > chars[i].size() - 1)
                {
                    digit_index[i] = 0;
                    digit_index[i-1] += 1;
                }
                ss.push_back(chars[i][digit_index[i]]);
            }
            digit_index[ll-1] += 1;
            ret.push_back(string(ss.rbegin(), ss.rend()));
            ret.push_back(ss);
        }
        return ret;
    }
};

int main()
{
    auto ret = Solution::letterCombinations("5678");
    cout << endl << ret.size() << endl;
    for (auto &s : ret)
        cout << s << endl;

    return 0;
}