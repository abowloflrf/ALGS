/**
 * 序列重构
 */

#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        int size = org.size();                         //目标序列长度
        unordered_map<int, unordered_set<int>> graph;  //将seqs构造为一个图
        vector<int> degrees(size + 1);  //保存每个节点的入度，没有0因此要+1
        int maxSize = 0;
        for (auto seq : seqs) {
            maxSize = max(maxSize, (int)seq.size());
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] < 1 || seq[i] > size)
                    return false;  // org为1-n的正整数序列，若存在之外的数则非法
                if (i == 0)
                    continue;  //每个序列中的第0个是没有节点指向它的直接跳过
                if (graph[seq[i - 1]].count(seq[i]) == 0) {
                    graph[seq[i - 1]].insert(seq[i]);  //构造图
                    degrees[seq[i]]++;                 //构造度数
                }
            }
        }

        if (maxSize == 0) return size == 0;

        //构造入度为0的队列，队列中保存的是索引
        queue<int> mQueue;
        for (int i = 1; i < degrees.size(); i++) {
            if (degrees[i] == 0) mQueue.push(i);
        }

        //开始从入度为0的节点pop
        int flag = 0;
        while (mQueue.size() ==
               1) {  //关键，队列中始终保持只有一个元素以保证构造的是唯一序列
            int index = mQueue.front();
            flag++;
            mQueue.pop();
            for (auto node : graph[index]) {
                if (--degrees[node] == 0) mQueue.push(node);
            }
        }

        //若构造唯一序列则flag==size
        return flag == size;
    }
};

int main() {
    Solution s = Solution();
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}};

    bool res = s.sequenceReconstruction(org, seqs);

    return 0;
}