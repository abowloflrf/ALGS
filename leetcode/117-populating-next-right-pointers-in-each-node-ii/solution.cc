/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (60.91%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    83.8K
 * Total Submissions: 137.5K
 * Testcase Example:  '[1,2,3,4,5,nullptr,7]'
 *
 * Given a binary tree
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to nullptr.
 *
 * Initially, all next pointers are set to nullptr.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,nullptr,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 6000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow-up:
 *
 *
 * You may only use constant extra space.
 * The recursive approach is fine. You may assume implicit stack space does not
 * count as extra space for this problem.
 *
 *
 */
#include <queue>
using namespace std;
class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> Q;
        if (!root)
            return nullptr;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                Node *node = Q.front();
                Q.pop();
                // 指向下一个节点，注意最后一个不要指向下一层了
                if (i < size - 1)
                    node->next = Q.front();

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end
