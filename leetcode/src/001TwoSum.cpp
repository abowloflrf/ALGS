#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[j] == target - nums[i])
                    return vector<int>{i, j};
    }

    vector<int> twoSum2(vector<int> &nums, int target)
    {
        //将给定的vector容器中的数据储存到一个unordered_map中
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        //对map进行一遍遍历
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end() && iter->second > i)
            {
                result.push_back(i);
                result.push_back(iter->second);
                break;
            }
        }
        return result;
    }
};
