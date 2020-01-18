#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution{
    public:
        static vector<vector<int>> fourSum(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());// 排序方便头尾相加
            vector<vector<int>> ret;
            map<int, bool> findKey;
            for(int i = 0; i < nums.size(); ++i)
            {
                if( i!= 0 && nums[i] == nums[i-1]) continue;
                auto num = nums[i];
                auto iter = nums.erase(nums.begin()+ i);
                auto temp = Solution::threeSum(nums, target-num);
                nums.insert(iter, num);
                for(auto& d :temp)
                {
                    bool insert = true;
                    for(auto i : d)
                        if(findKey.find(i) != findKey.end())
                        {
                            insert = false;
                            break;
                        }
                    if(insert)
                    {
                        d.push_back(num);
                        ret.push_back(d);
                    }
                }
                findKey[num] = true;
            }
            return ret;
        }

        static vector<vector<int>> threeSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
                if(nums.size() < 3){
                    return result;
                }

            for(int index = 0; index <= nums.size()-3; index++){
                while(index > 0 && index <= nums.size()-3 && nums[index] == nums[index-1]){index++;} // 前后相等，就直接下一个，因为会重复，这个index 从第二个数开始
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