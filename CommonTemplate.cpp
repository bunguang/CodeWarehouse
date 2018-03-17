//
// This file is for the common templates.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class CommonTemplate {
public:
    // 二分查找
    int binarySearch(vector<int> &nums, int start, int target) {
        int nLow = start, nHigh = nums.size();
        int nMid = 0;
        while (nLow <= nHigh) {
            nMid = (nLow + nHigh) / 2;
            if (nums[nMid] == target)
                return nMid;
            else if (nums[nMid] > target)
                nHigh = nMid - 1;
            else
                nLow = nMid + 1;
        }
        return -1;
    }

    // 快速排序

    // 归并排序

    // 层次遍历

    // 前序，后续，中序的循环实现

    // 深度优先 DFS

    // 广度优先 BFS

    // 最短路径 Dijsktra

    // 最小生成树 Prim

};

