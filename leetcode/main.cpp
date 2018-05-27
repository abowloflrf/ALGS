#include <vector>
#include "src/026RemoveDuplicatesFromSortedArray.cc"
using namespace std;
int main()
{
    Solution s = Solution();
    vector<int> vec = {1,1,2,2,2,3,3,3,4,5,6,8,8,8};
    int num = s.removeDuplicates2(vec);
    return 0;
}