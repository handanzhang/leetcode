/**
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
   A P L S I I G
   Y   I   R


Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
 */

#include <string>
#include <iostream>

using namespace std;

void Test(string s, int numRows)
{
    string s1 = string(s.size(), 'c');
    auto k = 0;
    for(int i = 0; i < numRows; ++i)
    {
        for(auto j = i; j < s.size(); j+=numRows+1)
        {
            if (i == numRows / 2)
            {
                s1[k] = s[j];
                if ((j+numRows - numRows / 2) < s.size())
                    k += 1;
                    s1[k] = s[j+numRows - numRows / 2];
            }
            else
            {
                s1[k] = s[j];
            }
            k += 1;
        }

    }
    std::cout << s1;
}


int main()
{
    Test("PAYPALISHIRING", 3);
}