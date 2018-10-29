#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DP:
// F[i,n] 代表root为i时，1-n个数字最多可以组成的不同BST数目
// G[n] 代表1-n个数字最多可以组成的不同BST数目
// F[i,n] = G[i-1]*G[n-i] 当root数字确定时，左右的两个子树其实也时连续的自然数
// 可组成的不同BST数目分别是G[i-1]和G[n-1]，组合即为G[i-1]*G[n-i]
// 又G[0]=0 G[1]= 1
// 且G[n] = F[1,n] + ... + F[n,n]
// G[n]就是要求的结果，就是所有可能的root的数量之和
// G[n] = G[0]*G[n-1] + G[1]*G[n-2] + ... + G[n-1]*G[0]
class Solution {
   public:
    int numTrees(int n) {
        vector<int> G(n + 1);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) {
            //计算G[i]
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(5) << endl;
    return 0;
}