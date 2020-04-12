/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (32.73%)
 * Likes:    1032
 * Dislikes: 460
 * Total Accepted:    176.6K
 * Total Submissions: 517.3K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * Example:
 *
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        auto r = helper(s, 0, 4);

        string addr;
        for (auto ip : r) {
            for (string p : ip) {
                addr += p;
                addr.push_back('.');
            }
            addr.pop_back();
            res.push_back(addr);
            addr = "";
        }
        return res;
    }

  private:
    // 从start位置开始，组成n段
    vector<vector<string>> helper(string &s, int start, int n) {
        int len = s.size() - start;
        if (len < n || len > 3 * n)
            return {};

        vector<vector<string>> res;
        if (n == 1) {
            string part1 = s.substr(start, s.size() - start);
            if (isValidPart(part1))
                res.push_back({part1});
            return res;
        }
        for (int i = 1; i <= 3 && start + i + n - 1 <= s.size(); i++) {
            // start 到 start+i 组成第一段，判断是否合法
            string part1 = s.substr(start, i);
            if (!isValidPart(part1)) {
                continue;
            }
            vector<vector<string>> leftPart = helper(s, start + i, n - 1);
            if (leftPart.empty())
                continue;
            for (auto l : leftPart) {
                l.insert(l.begin(), part1);
                res.push_back(l);
            }
        }
        return res;
    }

    // 判断单段是否有效 0-255
    bool isValidPart(string &s) {
        int ip = stoi(s);
        if (ip > 255)
            return false;
        if (s.size() >= 2 && s[0] == '0')
            return false;
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    auto r = s.restoreIpAddresses("25525511135");
    return 0;
}
