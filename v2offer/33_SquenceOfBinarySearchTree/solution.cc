#include <vector>
using namespace std;

class Solution {
  private:
    bool valid(vector<int> &postorder, int start, int end) {
        if (start > end || end >= postorder.size()) {
            return false;
        }
        if (start == end || end - start == 1)
            return true;
        int root = postorder[end];

        int leftEndIdx = start - 1;
        for (int i = start; i < end; i++) {
            if (postorder[i] < root) {
                leftEndIdx = i;
            } else {
                break;
            }
        }
        int rightEndIdx = leftEndIdx;
        for (int i = leftEndIdx + 1; i < end; i++) {
            if (postorder[i] > root) {
                rightEndIdx = i;
            } else {
                return false;
            }
        }
        bool v = rightEndIdx == end - 1;
        if (leftEndIdx == start - 1 || rightEndIdx == leftEndIdx) {
            return v && valid(postorder, start, end - 1);
        }
        return v && valid(postorder, start, leftEndIdx) && valid(postorder, leftEndIdx + 1, end - 1);
    };

  public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty())
            return true;
        return valid(postorder, 0, postorder.size() - 1);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> data = {1, 2, 3, 4, 5};
    Solution s;
    bool a = s.verifyPostorder(data);
    return 0;
}
