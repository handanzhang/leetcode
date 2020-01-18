#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    public:
        static vector<vector<int>> fourSum(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());// 排序方便头尾相加
            vector<vector<int>> ret;
            for(int i = 0; i < nums.size(); ++i)
            {
                if( i!= 0 && nums[i] == nums[i-1]) continue;
                auto num = nums[i];
                auto temp = Solution::threeSum(nums, i+1, target-num); //已经遍历过的num不应该计入可选数字内，所以开始的数字为i+1
                for(auto& d :temp)
                {
                    d.push_back(num);
                    ret.push_back(d);
                }
            }
            return ret;
        }

        static vector<vector<int>> threeSum(vector<int>& nums, int startIndex, int target) {
            vector<vector<int>> result;
                if(nums.size() < 3){
                    return result;
                }

            for(int index = startIndex; index <= nums.size()-3; index++){
                while(index > startIndex && index <= nums.size()-3 && nums[index] == nums[index-1]){index++;} // 前后相等，就直接下一个，因为会重复，这个index 从第二个数开始
                int i = index+1; // 指针头
                int j = nums.size()-1; //指针尾
                while(i < j){
                    if(nums[i] + nums[j] + nums[index] == target){
                        result.push_back({nums[i], nums[j], nums[index]});
                        while(i<j && nums[i] == nums[i+1]){i++;} // ==直接往后+
                        while(i<j && nums[j] == nums[j-1]){j--;}
                        i++; j--;
                    }
                    else if(nums[i] + nums[j] + nums[index] > target){
                        j--;
                    }else{
                        i++;
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<int> tt = {1,0,-1,0,-2,2};
    auto ret = Solution::fourSum(tt, 0);
    cout <<endl <<ret.size() <<endl;
    for(auto& d:ret)
    {
        for (auto n: d)
            cout << n << "  ";
        cout << endl;
    }
}