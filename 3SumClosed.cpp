#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

/*
    不管是3Sum还是本题，精髓都在于，2个指针找一个固定的范围，用双指针来快速遍历一个范围
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int l, r;
    sort(nums.begin(),nums.end());
    int mini = INT_MAX;
    int req;
        int sum = target;
    for (int i = 0; i < nums.size() - 2; i++) {
        l = i + 1;

        r = nums.size() - 1; // index of the last element
        while (l < r) {
        	int temp = nums[i] + nums[l] + nums[r];
        	int temp2 = abs(temp-sum);
        	if(mini>temp2){
        		req = nums[i] + nums[l] + nums[r];
        		mini = temp2;
        	}
            if (temp == sum) {
                return sum;
            }
            else if (nums[i] + nums[l] + nums[r] < sum)
                l++;

                 /*
                 这里为什么不往回走，比如 r--?
                 假如  xi + xj > sum 这时候有2个情况，
                    1. xi-1 + xj 这种如果 > sum 那么 xi+xj 会大的更多，没有任何意义，如果小于 < sum, 那么又分为2种情况， 一种不停回退，一种变到刚才的表达式
                        然后进入无尽循环中， 显然不行
                    2. xi + xj+1
                 */
            else
                r--;
        }
    }
    return req;
};
};

int main()
{
    vector<int> ss = {1,2,4,8,16,32,64,128};
    cout <<endl;
    cout << Solution::threeSumClosest(ss, 82);
}