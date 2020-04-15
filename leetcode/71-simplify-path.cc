/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (29.98%)
 * Likes:    684
 * Dislikes: 1626
 * Total Accepted:    194.6K
 * Total Submissions: 617.7K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 *
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 *
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 *
 *
 * Example 2:
 *
 *
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 *
 *
 * Example 3:
 *
 *
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 *
 *
 * Example 4:
 *
 *
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 *
 *
 * Example 5:
 *
 *
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 *
 *
 * Example 6:
 *
 *
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 *
 *
 */
#include <deque>
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    string simplifyPath(string path) {
        int idx = 1;

        deque<string> pathStack;
        while (idx < path.size()) {
            string tmp;
            // 去取个/中间的部分
            while (idx < path.size()) {
                if (path[idx] != '/') {
                    tmp += path[idx];
                    idx++;
                } else {
                    idx++;
                    break;
                }
            }

            if (tmp == "." || tmp == "") {  // .或空表示依然当前目录，
                continue;
            } else if (tmp == "..") {       // .. 表示上一级目录，栈pop出上一次的部分，若已经是根则还是根
                if (!pathStack.empty()) {
                    pathStack.pop_back();
                }
            } else {                        // 正常路径，直接入栈
                pathStack.push_back(tmp);
            }
        }
    
        string res;
        if (pathStack.empty()) {
            return "/";
        }
        while (!pathStack.empty()) {
            res += ("/" + pathStack.front());
            pathStack.pop_front();
        }
        return res;
    }
};
// @lc code=end
int main() {
    Solution s;
    string r = s.simplifyPath("/a//b////c/d//././/..");
    return 0;
}