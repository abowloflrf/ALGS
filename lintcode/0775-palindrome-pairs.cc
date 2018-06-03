#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //结果
        set<vector<int>> result;
        //遍历 words 将反转的字符与其原下标保存在map中
        unordered_map<string, int> table;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            reverse(w.begin(), w.end());
            table[w] = i;
        }
        //遍历 words 开始判断回文对
        for (int i = 0; i < words.size(); i++) {
            //将字符串分割为左右两个部分
            // 1. j=0
            // 时表示最左侧分割，lstr==""，需要在map中找到rstr即完整words[i]的回文
            // 2. j=words[i].size()
            // 时表示最右侧分割，需要在map中找到lstr即完整words[i]的回文
            // 3.
            // 从中间分割，若左半部分lstr是本身是回文，则需要在map中找到右半部分rstr的回文
            //右半部分同理
            for (int j = 0; j <= words[i].size(); j++) {
                string word = words[i];  //将遍历到的字符串保存
                string lstr = word.substr(0, j);  //分割左部分
                string rstr = word.substr(j, word.size() - j);  //分割右部分

                if (isPalindro(lstr) && table.find(rstr) != table.end() &&
                    table[rstr] != i)
                    result.insert({table[rstr], i});
                if (isPalindro(rstr) && table.find(lstr) != table.end() &&
                    table[lstr] != i)
                    result.insert({i, table[lstr]});
            }
        }
        vector<vector<int>> res(result.begin(), result.end());
        return res;
    }

   private:
    //判断字符串本身是否是回文的
    bool isPalindro(string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll", ""};
    vector<vector<int>> res = s.palindromePairs(words);
    return 0;
}