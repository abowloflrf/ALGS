#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> cidr(string start_ip, int range) {
        vector<string> result;
        uint32_t start = ipToNumber(start_ip), end = start + range - 1;
        while (start <= end) {
            uint32_t val = start & (-start);
            val = min(val, (uint32_t)range);
            int pos = indexOf(val);
            int mask = 32 - pos;
            result.push_back(numberToIp(start) + "/" + to_string(mask));
            start += 1 << pos;
        }
        return result;
    }

   private:
    uint32_t ipToNumber(string ipstr) {
        int n = ipstr.size();
        uint32_t res = 0, node = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n || ipstr[i] == '.') {
                res = (res << 8) + node;
                node = 0;
            } else {
                node = node * 10 + ipstr[i] - '0';
            }
        }
        return res;
    }

    string numberToIp(uint32_t ipnumber) {
        string s;
        for (int i = 0; i < 4; i++) {
            s = (i != 3 ? "." : "") + to_string(ipnumber % 256) + s;
            ipnumber = ipnumber >> 8;
        }
        return s;
    }

    int indexOf(uint32_t num) {
        int count = 0;
        for (; num != 1; num >>= 1) {
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<string> result = s.cidr("192.168.1.32", 31);
    for (auto c : result) {
        cout << c << "\n";
    }
    return 0;
}
