#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Implement a CSVReader class that will read a comma-separated-values (CSV)
// file from disk, parse it, and print out the parsed elements with some other
// separator.

// * The input delimiter is the comma, ","
// * If that delimiter is contained within an element, then that element must be
// quoted
// * If quotes are contained in an element, then that element must be quoted and
// use double inner quotes (escape character)

// input

// John,Smith,john.smith@gmail.com,Los Angeles,1
// Jane,Roberts,janer@msn.com,"San Francisco, CA",0
// "Alexandra ""Alex""",Menendez,alex.menendez@gmail.com,Miami,1
// one,two,,four,"five"

// output

// John|Smith|john.smith@gmail.com|Los Angeles|1
// Jane|Roberts|janer@msn.com|San Francisco, CA|0
// Alexandra "Alex"|Menendez|alex.menendez@gmail.com|Miami|1
// one|two||four|five

// To execute C++, please define "int main()"

string parseCSV(string str) {
    int len = str.size();
    bool isInMark = false;
    vector<string> res;
    string node;
    for (int i = 0; i < len; i++) {
        //不在引号内
        if (!isInMark) {
            //遇到引号则进入引号（只要这项元素中含有逗号或者引号则其一定会使用引号包括）
            //因此在引号外遇到引号必定标志的新的元素的开始
            if (str[i] == '"') {
                isInMark = true;
                continue;
            }
            //遇到逗号则完成此列的计算加入到结果数组
            if (str[i] == ',') {
                res.push_back(node);
                node = "";
                continue;
            }
            //常规字符
            node += str[i];
            continue;
        }

        //在引号内
        if (isInMark) {
            //连续遇到两个引号则转义（i+1<len保证下一个字符不会溢出）
            if (str[i] == '"' && i + 1 < len && str[i + 1] == '"') {
                node += '"';
                i++;
                continue;
            }
            //再次遇到引号则直接完成该元素
            //因为上面已经判断了连续两个引号的情况，因此这里遇到的必定是单独的引号（表示元素的结束）
            if (str[i] == '"') {
                isInMark = false;
                continue;
            }
            node += str[i];
            continue;
        }
    }

    //加入最后计算的一列
    if (!node.empty()) res.push_back(node);

    //构建输出字符串
    string resString;
    for (int i = 0; i < res.size(); i++) {
        if (i == 0)
            resString += res[i];
        else
            resString += "|" + res[i];
    }

    return resString;
}

int main() {
    string str =
        "John,Smith,,john.smith@gmail.com,Los Angeles,1,\"San Francisco, "
        "CA\",\"Alexandra \"\"Alex\"\"\"";
    string result = parseCSV(str);
    cout << result << endl;
    return 0;
}