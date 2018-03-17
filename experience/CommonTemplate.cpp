//
// This file is for the common templates.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct EdgeNode { // 边表节点类型
    int to, w; // 顶点序号和边长
};

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

    void createAdjList() {
        vector<EdgeNode> map[10];
        EdgeNode e;
        int n, m, i, j, k, w;
        cin >> n >> m; //n个顶点m组数据

        for(i = 0; i < m; ++i){
            cin >> j >> k >> w;
            e.to = k; e.w = w;
            map[j].push_back(e);
        }

        //遍历
        for(i = 1; i <= n; ++i){
            for(vector<EdgeNode>:: iterator k = map[i].begin();
                k != map[i].end(); ++k){
                EdgeNode t = *k;
                cout << i << ' ' << t.to << ' ' << t.w << endl;
            }
        }
    }

    // 创建图的邻接表

    // 快速排序 (数构书上有，优先级不高)

    // 层次遍历
    void levelOrder(BinaryTreeNode *root) {
        queue<BinaryTreeNode*> treeQueue;
        if (root == NULL) return;
        treeQueue.push(root);
        while (treeQueue.size() != 0) {
            BinaryTreeNode* tmpNode = treeQueue.front();
            treeQueue.pop();
            cout << tmpNode->val << " ";
            if (tmpNode->left != NULL) treeQueue.push(tmpNode->left);
            if (tmpNode->right != NULL) treeQueue.push(tmpNode->right);
        }
    }

    // 前序，后续，中序的循环实现 (优先级不高)

    // 深度优先 DFS (数构书上有，优先级不高)

    // 广度优先 BFS (数构书上有，优先级不高)

    // 最短路径 Dijsktra (数构书上有，优先级不高)

    // 最小生成树 Prim (数构书上有，优先级不高)

};

//int main() {
//    CommonTemplate commonTemplate;
//
//    BinaryTreeNode *n1 = new BinaryTreeNode(1);
//    BinaryTreeNode *n2 = new BinaryTreeNode(3);
//    BinaryTreeNode *n3 = new BinaryTreeNode(2);
//    BinaryTreeNode *n4 = new BinaryTreeNode(5);
//    BinaryTreeNode *n5 = new BinaryTreeNode(8);
//    BinaryTreeNode *n6 = new BinaryTreeNode(6);
//    BinaryTreeNode *n7 = new BinaryTreeNode(7);
//
//    n1->left = n2, n1->right = n3;
//    n2->left = n4, n2->right = n5;
//    n3->left = n6, n3->right = n7;
//
//    commonTemplate.levelOrder(n1);
//
//    return 0;
//}

