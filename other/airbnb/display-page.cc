#include <iostream>
#include <list>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

list<string> displayPages(list<string> input, int pageSize) {
    list<string> res;
    list<string>::iterator itr = input.begin();
    unordered_set<string> hostSet;  //保存当前页的host set
    int count = 0;
    bool reachEnd = false;

    while (itr != input.end()) {
        string curLine = *itr;
        string hostId;

        //解析得到该条记录的hostid
        for (int i = 0; i < curLine.size(); i++) {
            if (curLine[i] != ',')
                hostId += curLine[i];
            else
                break;
        }

        //添加到当前页，两种情况
        // 1. 当前页host set没有这个host，可以添加
        // 2. reachend 搜索到底部，则加入一个头部的重复host
        if (hostSet.count(hostId) == 0 || reachEnd) {
            res.push_back(curLine);  //加入当前记录
            hostSet.insert(hostId);  //把hostid加入到当前页set
            itr = input.erase(itr);  //删除这条记录
            count++;
        } else {
            itr++;  //这里关键，若这条记录不符合要求，迭代器要+1
        }

        //翻页，并将记录数据情况
        if (count == pageSize) {
            if (!input.empty()) res.push_back("\n");
            hostSet.clear();      //清空当前页记录的host set
            count = 0;            //清空当前页的记录数
            itr = input.begin();  //将迭代器再指向头部
        }

        //搜索到全部未找到非重复的hostid
        if (itr == input.end()) {
            reachEnd = true;
            itr = input.begin();
        }
    }
    return res;
}

int main() {
    list<string> inputData;
    inputData.push_back("1,28,300.1,San Francisco");
    inputData.push_back("4,5,209.1,San Francisco");
    inputData.push_back("20,7,208.1,San Francisco");
    inputData.push_back("23,8,207.1,San Francisco");
    inputData.push_back("16,10,206.1,Oakland");
    inputData.push_back("1,16,205.1,San Francisco");
    inputData.push_back("6,29,204.1,San Francisco");
    inputData.push_back("7,20,203.1,San Francisco");
    inputData.push_back("8,21,202.1,San Francisco");
    inputData.push_back("2,18,201.1,San Francisco");
    inputData.push_back("2,30,200.1,San Francisco");
    inputData.push_back("15,27,109.1,Oakland");
    inputData.push_back("10,13,108.1,Oakland");
    inputData.push_back("11,26,107.1,Oakland");
    inputData.push_back("12,9,106.1,Oakland");
    inputData.push_back("13,1,105.1,Oakland");
    inputData.push_back("22,17,104.1,Oakland");
    inputData.push_back("1,2,103.1,Oakland");
    inputData.push_back("28,24,102.1,Oakland");
    inputData.push_back("18,14,11.1,San Jose");
    inputData.push_back("6,25,10.1,Oakland");
    inputData.push_back("19,15,9.1,San Jose");
    inputData.push_back("3,19,8.1,San Jose");
    inputData.push_back("3,11,7.1,Oakland");
    inputData.push_back("27,12,6.1,Oakland");
    inputData.push_back("1,3,5.1,Oakland");
    inputData.push_back("25,4,4.1,San Jose");
    inputData.push_back("5,6,3.1,San Jose");
    inputData.push_back("29,22,2.1,San Jose");
    inputData.push_back("30,23,1.1,San Jose");

    list<string> res = displayPages(inputData, 5);
    return 0;
}