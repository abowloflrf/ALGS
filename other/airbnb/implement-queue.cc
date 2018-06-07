// #include <iostream>
// #include <list>
// #include <vector>

// using namespace std;

// class Queue {
//    private:
//     const int maxSize = 5;
//     list<vector<int>> mList;
//     int head = 0;
//     int tail = 0;
//     int totalCount = 0;
//     int listCount = 0;

//    public:
//     void enqueue(int val) {
//         if (tail == maxSize - 1) {
//             vector<int> newNode;
//             newNode.push_back(val);
//             tail = 0;
//             listCount++;
//             mList.push_back(newNode);
//         } else {
//             (*mList.end()).push_back(val);
//             tail++;
//         }
//         totalCount++;
//     }
//     int pop() {
//         if (totalCount == 0) return NULL;
//         int res;
//         vector<int> frontVec = *mList.begin();
//         res = frontVec[0];
//         frontVec.erase(frontVec.begin());
//         if (head == 0) {
//             mList.pop_front(mList.begin());
//             listCount--;

//         }

//         totalCount--;
//     }
//     int size() {}
//     int getHead() {}
//     int getTail() {}
// }