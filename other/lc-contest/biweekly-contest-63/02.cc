#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool winnerOfGame(string colors) {
        if (colors.size() < 3)
            return false;
        // 检查连续 A 的数量和 连续 B 的数量，比谁打
        int termA = 0, termB = 0;
        int i = 0;
        char currentTerm = colors[0];
        int count = 1;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == currentTerm) {
                count++;
            } else {
                if (count >= 3) {
                    int delta = count - 2;
                    if (currentTerm == 'A') {
                        termA += delta;
                    } else {
                        termB += delta;
                    }
                }
                count = 1;
                currentTerm = colors[i];
            }
        }
        // 最后结束也要加一下
        if (count >= 3) {
            int delta = count - 2;
            if (currentTerm == 'A') {
                termA += delta;
            } else {
                termB += delta;
            }
        }

        if (termA == termB) {
            return false;
        }
        return termA > termB;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    bool a = s.winnerOfGame("AAAABBBB");
    return 0;
}
