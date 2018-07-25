//
// Created by ruofeng on 2018/7/25.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//JKL分别是11、12、13，大小王可以当作任意数字，这里看作0
//0-13
bool isContinuous(vector<int> cards) {
    //由于这里扑克牌一共只有固定种数，因此可以考虑使用数组而不使用快排
    int sortedArr[14] = {0};
    for (auto c:cards)
        sortedArr[c]++;
    vector<int> sortedCards;
    for (int i = 0; i < 14; ++i) {
        if (sortedArr[i] == 0)continue;
        for (int j = 0; j < sortedArr[i]; ++j) {
            sortedCards.push_back(i);
        }
    }
    //sort(cards.begin(), cards.end());
    int zeroNumber = 0;
    int gapNumber = 0;
    int lastCard = -1;
    for (auto card:sortedCards) {
        if (card == 0) {
            zeroNumber++;
            continue;
        }
        if (lastCard == -1) {
            lastCard = card;
            continue;
        } else {
            if (card == lastCard) return false;
            gapNumber += (card - lastCard - 1);
            lastCard = card;
        }
    }
    return zeroNumber == gapNumber;
}

int main() {
    vector<int> cards = {7, 3, 4, 0, 0};
    cout << isContinuous(cards) << endl;
    return 0;
}
