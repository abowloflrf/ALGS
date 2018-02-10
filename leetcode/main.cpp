#include <iostream>
#include <string>
#include <vector>
#include "./src/001TwoSum.cpp"
int main()
{
    Solution test = Solution();
    std::vector<int> v_data = {2, 7, 11, 15, 21};
    std::vector<int> v_result = test.twoSum2(v_data, 26);
    return 0;
}