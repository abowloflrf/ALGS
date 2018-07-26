#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        //处理空容器以及只有一个容量的容器情况
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        string commonStr = "";
        char c;
        int indexChar = 0;
        while (true) {
            int indexStr = 0;
            bool isSame = true;
            for (auto str : strs) {
                //防止出现遍历到的字符串长度过短无法访问到指定位数的字符
                if (str.length() <= indexChar) {
                    isSame = false;
                    break;
                }
                //首个字符串不用比较直接取字符即可
                c = str[indexChar];
                if (indexStr == 0) {
                    indexStr++;
                    continue;
                }
                //将此字符串的指定位数字符与上一个字符串比较，若不相同则直接跳出循环表明不用继续寻找
                isSame = (str[indexChar] == strs[indexStr - 1][indexChar]);
                if (!isSame) break;
                indexStr++;
            }
            if (isSame)
                commonStr += c;
            else
                break;
            indexChar++;
        }
        return commonStr;
    }
};