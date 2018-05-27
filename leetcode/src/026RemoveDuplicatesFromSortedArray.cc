#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        for (auto iter = nums.begin() + 1; iter != nums.end(); iter++)
        {
            if (*iter == *(iter - 1))
            {
                nums.erase(iter);
                iter--;
            }
        }
        return nums.size();
    }
};