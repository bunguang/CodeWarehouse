//
// Created by bunguang on 2018/3/17.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> chatOrder(vector<vector<int>> nums) {
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        int line_size = nums[i].size();
        vector<int> line;
        for (int j = line_size - 1; j >= 0; j--) {
            if (find(line.begin(), line.end(), nums[i][j]) == line.end())
                line.insert(line.end(), nums[i][j]);
        }
        result.insert(result.end(), line);
    }

    return result;
}

//int main() {
//    vector<vector<int>> nums;
//    int nums_size;
//    cin >> nums_size;
//    for (int i = 0; i < nums_size; i++) {
//        int line_size;
//        cin >> line_size;
//        vector<int> tmp;
//        for (int j = 0; j < line_size; j++) {
//            int each_num;
//            cin >> each_num;
//            tmp.insert(tmp.end(), each_num);
//        }
//        nums.insert(nums.end(), tmp);
//    }
//
//    vector<vector<int>> result = chatOrder(nums);
//
//    for (int i = 0; i < result.size(); i++) {
//        for (int j = 0; j < result[i].size(); j++) {
//            if (j == result[i].size() - 1) cout << result[i][j];
//            else cout << result[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

