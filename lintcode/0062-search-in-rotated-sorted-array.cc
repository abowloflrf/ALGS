#include <vector>
using namespace std;
class Solution {
   public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        if (A.empty()) return -1;
        int left = 0;
        int right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[left] <= A[mid]) {
                if (target < A[mid] && target >= A[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > A[mid] && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (target == A[left]) return left;
        if (target == A[right]) return right;
        return -1;
    }
};