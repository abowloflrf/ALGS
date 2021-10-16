#include <vector>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        // sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        sort(intervals.begin(), intervals.end(), cmp);

        int prevEnd = -1;
        for (auto &i : intervals) {
            if (i[0] < prevEnd)
                return false;
            prevEnd = i[1];
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> intervals = {{7, 10}, {2, 4}};
    bool ans = s.canAttendMeetings(intervals);
    return 0;
}
