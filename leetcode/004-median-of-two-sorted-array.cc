// 给定两个排好序的数组，得到其中位数，目前是O(m+n)，最优解为O(log(m+n))

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalSize = size1 + size2;
        int index1 = 0, index2 = 0;
        int lastVal = 0;
        int currVal = 0;
        while ((index1 + index2) < totalSize / 2 + 1) {
            lastVal = currVal;
            if (index1 < size1 && index2 < size2)
                currVal = nums1[index1] < nums2[index2] ? nums1[index1++] : nums2[index2++];
            else
                //某个数组到尽头，则直接加另外一个数组的内容
                currVal = index1 >= size1 ? nums2[index2++] : nums1[index1++];
        }
        return (totalSize & 1) ? (double)currVal : (double)(currVal + lastVal) / 2;
    }
};

int main() {
    vector<int> n1 = {1, 2, 7, 8};
    vector<int> n2 = {3, 4, 5};
    Solution s;
    cout << s.findMedianSortedArrays(n1, n2) << endl;
    return 0;
}