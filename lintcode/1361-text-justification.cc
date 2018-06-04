/**
 * Text Justification
 * 给定一组单词，与一个正整数maxWidth表示一行最长长度
 * 要求对这一组单组分行，要求单词之间的space数目尽可能相等
 * 最后一行要求向左对齐
 */

#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    /**
     * @param words: an array of string
     * @param maxWidth: a integer
     * @return: format the text such that each line has exactly maxWidth
     * characters and is fully
     */
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        int n = words.size();
        vector<string> line;
        vector<string> result;
        int lineLength = 0;
        for (int i = 0; i < n; i++) {
            if (lineLength == 0) {  //新的一行
                lineLength += words[i].length();
                line.push_back(words[i]);
            } else if (lineLength + words[i].length() + 1 <= maxWidth) {
                lineLength = lineLength + words[i].length() + 1;
                line.push_back(" " + words[i]);
            } else {
                // justification
                string s = "";
                if (line.size() == 1) {
                    s += (line[0] + string(maxWidth - lineLength, ' '));
                } else {
                    int baseN = (maxWidth - lineLength) / (line.size() - 1);
                    int moreIndex = (maxWidth - lineLength) % (line.size() - 1);
                    for (int j = 0; j < line.size(); j++) {
                        if (j == 0)
                            s += line[j];
                        else if (j - 1 < moreIndex)
                            s += (string(baseN + 1, ' ') + line[j]);
                        else
                            s += (string(baseN, ' ') + line[j]);
                    }
                }
                // push
                result.push_back(s);
                line.clear();
                lineLength = 0;
                i--;
            }
        }
        //加入最后一行
        string s = "";
        if (!line.empty()) {
            for (int i = 0; i < line.size(); i++) {
                s += line[i];
            }
        }
        s += string(maxWidth - lineLength, ' ');
        result.push_back(s);

        //返回结果
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<string> strs = {"What",           "must",  "be",
                           "acknowledgment", "shall", "be"};
    int maxWidth = 16;
    vector<string> result = s.fullJustify(strs, maxWidth);
    return 0;
}