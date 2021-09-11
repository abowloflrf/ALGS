#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxmiumScore(vector<int> &cards, int cnt) {
        sort(cards.begin(), cards.end(), greater<int>());
        vector<int> odd;  // 奇数
        vector<int> even; // 偶数
        for (int c : cards) {
            if (c % 2) {
                odd.push_back(c);
            } else {
                even.push_back(c);
            }
        }
        // 无效
        if (even.size() == 0 && (cnt % 2)) {
            return 0;
        }
        if (cnt == cards.size() && odd.size() % 2) {
            return 0;
        }
        // 贪心
        int ans = 0, currentCnt = 0;
        int oddIdx = 0, evenIdx = 0;
        while (currentCnt != cnt) {
            if (evenIdx >= even.size()) {
                // 已无偶数，全取奇数
                while (currentCnt != cnt) {
                    ans += (odd[oddIdx] + odd[oddIdx + 1]);
                    oddIdx += 2;
                    currentCnt += 2;
                }
                return ans;
            }
            if (oddIdx >= odd.size()) {
                // 已无奇数，全取偶数
                while (currentCnt != cnt) {
                    ans += even[evenIdx];
                    evenIdx++;
                    currentCnt++;
                }
                return ans;
            }
            if (evenIdx == even.size() - 1) {
                // 若偶数只剩一个，根据 currentCnt 判断
                if ((cnt - currentCnt) % 2) {
                    // 剩余能取奇数个，一个偶+所有能取的奇数
                    ans += even[evenIdx++];
                    currentCnt++;
                    while (currentCnt != cnt) {
                        ans += (odd[oddIdx] + odd[oddIdx + 1]);
                        oddIdx += 2;
                        currentCnt += 2;
                    }
                } else {
                    // 剩余能取偶数个，全部取奇数
                    while (currentCnt != cnt) {
                        ans += (odd[oddIdx] + odd[oddIdx + 1]);
                        oddIdx += 2;
                        currentCnt += 2;
                    }
                }
                return ans;
            }
            if (oddIdx == odd.size() - 1) {
                // 若奇数只剩一个，把偶数全部取完即可
                while (currentCnt != cnt) {
                    ans += even[evenIdx];
                    evenIdx++;
                    currentCnt++;
                }
                return ans;
            }
            // 只剩一个，取偶数即可
            if (currentCnt == (cnt - 1)) {
                ans += even[evenIdx];
                return ans;
            }

            // 都剩大于1个，且能取一个以上，则比较 两个奇数相加和两个偶数相加的和
            int oddTarget = odd[oddIdx] + odd[oddIdx + 1];
            int evenTarget = even[evenIdx] + even[evenIdx + 1];
            if (oddTarget > evenTarget) {
                ans += oddTarget;
                oddIdx += 2;
                currentCnt += 2;
            } else {
                ans += even[evenIdx];
                evenIdx++;
                currentCnt++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> cards = {1, 3, 5, 7, 9};
    int ans = s.maxmiumScore(cards, 4);
    return 0;
}
