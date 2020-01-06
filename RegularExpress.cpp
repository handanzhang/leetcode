/**
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

notes: The matching should cover the entire input string (not partial).

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

*/

/**
 * 从基础开始，如果没有*，那么只需要逐字对比即可， 有了* 就需要考虑多考虑一位
 * 没有 * 的
 *  def match(text, pattern):
        if not pattern: return not text
        first_match = bool(text) and pattern[0] in {text[0], '.'}
        return first_match and match(text[1:], pattern[1:])
    
    有 * 递归解法
    def isMatch(self, text, pattern):
        if not pattern:
            return not text

        first_match = bool(text) and pattern[0] in {text[0], '.'}

        if len(pattern) >= 2 and pattern[1] == '*':
            return (self.isMatch(text, pattern[2:]) or  
                    first_match and self.isMatch(text[1:], pattern))  # 这里多了几步，要不特殊匹配用掉，要么待匹配字符串缩短
        else:
            return first_match and self.isMatch(text[1:], pattern[1:])

    采用 dynamic program的解法，拆分为多个子问题求解，每个子问题的结果都缓存起来，步骤n 包含 步骤n-1,n-2等等，
    class Solution(object):
    def isMatch(self, text, pattern):
        dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)] 

        dp[-1][-1] = True 
        for i in range(len(text), -1, -1):   # 保证问题的每一个子集都被遍历到
            for j in range(len(pattern) - 1, -1, -1): #从最小问题求解
                first_match = i < len(text) and pattern[j] in {text[i], '.'} 
                if j+1 < len(pattern) and pattern[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j] # 缓存子问题
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]

        return dp[0][0] # 查询最大问题解
 * 
 */


#include <string>
#include <iostream>

using namespace std;

int main()
{
    auto s = "mississippi"
    auto p = "mis*is*p*."

    cout << isMatch(s, p)

}