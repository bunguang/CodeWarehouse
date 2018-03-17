//
// This file is for the solution of bunguang-self.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BunSolution {
public:

    void mirrorBinaryTree(BinaryTreeNode *root) {
        if (root == NULL) return;
        BinaryTreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorBinaryTree(root->left);
        mirrorBinaryTree(root->right);
    }

    void printNums(vector<int> nums) {
        int length = nums.size();
        for (int i = 0; i < length; i++) cout << nums[i] << " ";
        cout << endl;
    }

    void permutation(vector<int> nums, int start) {
        int end = nums.size() - 1;
        if (start == end) printNums(nums);
        else {
            for (int i = start; i <= end; i++) {
                int tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;
                permutation(nums, start + 1);
                tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;
            }
        }

    }

    void permutation(vector<int> nums) {
        permutation(nums, 0);
    }

    void judge(vector<int> nums) {
        int length = nums.size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (j - i == abs(nums[i] - nums[j])) {
                    return;
                }
            }
        }
        printNums(nums);
    }

    void eight_queens(vector<int> nums, int start) {
        int end = nums.size() - 1;
        if (start == end) judge(nums);
        else {
            for (int i = start; i <= end; i++) {
                int tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;
                eight_queens(nums, start + 1);
                tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;
            }
        }
    }

    void eight_queens() {
        vector<int> checkboards = {0, 1, 2, 3, 4, 5, 6, 7};
        eight_queens(checkboards, 0);
    }

};

string stringEncoding(string str) {
    string result = "";
    if (str.size() == 0) return str;
    int count = 1;
    char tmpChar = str[0];
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == tmpChar) count++;
        else {
            result = result + to_string(count) + tmpChar;
            count = 1;
            tmpChar = str[i];
        }
    }
    result = result + to_string(count) + tmpChar;
    return result;
}

int maxSummary(int N, int D, vector<vector<int>> &nums) {
    int max = 0;
    int sum = 0;
    // Heng
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[i][j];
        if (sum > max) max = sum;
        for (int j = 0; j < N - D; j++) {
            sum = sum - nums[i][j] + nums[i][j + D];
            if (sum > max) max = sum;
        }
    }
    // Shu
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[j][i];
        if (sum > max) max = sum;
        for (int j = 0; j < N - D; j++) {
            sum = sum - nums[j][i] + nums[j + D][i];
            if (sum > max) max = sum;
        }
    }
    // Zuoshang - Youxia
    for (int i = 0; i < N - D + 1; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[j][i + j];
        if (sum > max) max = sum;
        for (int j = 0; j < N - i - D; j++) {
            sum = sum - nums[j][i + j] + nums[j + D][i + j + D];
            if (sum > max) max = sum;
        }
    }
    for (int i = 1; i < N - D + 1; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[i + j][j];
        if (sum > max) max = sum;
        for (int j = 0; j < N - i - D; j++) {
            sum = sum - nums[i + j][j] + nums[i + j + D][j + D];
            if (sum > max) max = sum;
        }
    }
    // Youshang - Zuoxia
    for (int i = 0; i < N - D + 1; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[j][N - 1 - (i + j)];
        if (sum > max) max = sum;
        for (int j = 0; j < N - i - D; j++) {
            sum = sum - nums[j][N - 1 - (i + j)] + nums[j + D][N - 1 - (i + j) - D];
            if (sum > max) max = sum;
        }
    }
    for (int i = 1; i < N - D + 1; i++) {
        sum = 0;
        for (int j = 0; j < D; j++) sum = sum + nums[i + j][N - 1 - j];
        if (sum > max) max = sum;
        for (int j = 0; j < N - i - D; j++) {
            sum = sum - nums[i + j][N - 1 - j] + nums[i + j + D][N - 1 - j - D];
            if (sum > max) max = sum;
        }
    }
    return max;
}

int random(int x) {
    return rand() % x;
}

vector<int> new_initialize_array(int array_size = 100) {
    vector<int> v1;
    for (int i = 0; i < array_size; i++) v1.push_back(i);
    return v1;
}

void new_random100(vector<int> v1) {
    int count = 1;
    int vector_size = v1.size();
    for (int i = vector_size - 1; i >= 0; i--) {
        srand((unsigned)time(NULL));
        int random_index = random(i + 1);
        cout << count << "\t" << v1[random_index] << endl;
        int tmp = v1[random_index];
        v1[random_index] = v1[i];
        v1[i] = tmp;
        count++;
    }
}

void new_random100_address(vector<int>& v1) {
    int count = 1;
    int vector_size = v1.size();
    for (int i = vector_size - 1; i >= 0; i--) {
        srand((unsigned)time(NULL));
        int random_index = random(i + 1);
        cout << count << "\t" << v1[random_index] << endl;
        int tmp = v1[random_index];
        v1[random_index] = v1[i];
        v1[i] = tmp;
        count++;
    }
}

int main() {
    BunSolution bunSolution;

    /*
//    vector<int> num_array = {2, 7, 11, 15};
//    int target = 22;
//    vector<int> result = solution.twoSum(num_array, target);

//    ListNode *n11 = new ListNode(9);
//    ListNode *n12 = new ListNode(8);
//    ListNode *n13 = new ListNode(7);
//    n12->next = n13;
//    n11->next = n12;
//    ListNode *n21 = new ListNode(9);
//    ListNode *n22 = new ListNode(8);
//    ListNode *n23 = new ListNode(7);
//    ListNode *n24 = new ListNode(9);
//    n23->next = n24;
//    n22->next = n23;
//    n21->next = n22;
//    ListNode *l3 = solution.addTwoNumbers(n11, n21);

//    vector<int> nums = {0,0,0,-1,-2,-3,100};
//    vector<vector<int>> result = solution.threeSum(nums);

//    vector<string> strs = {"1234567", "1234", "123", "122"};
//    string prefix = solution.longestCommonPrefix(strs);

//    int test_num = 1234554321;
//    bool flag = solution.isPalindrome(test_num);

//    int num = solution.romanToInt("XIV");
//    string bunStr = solution.intToRoman(14);
//    int length = solution.lengthOfLongestSubstring("dvdf");

//    vector<int> nums1 = {1, 2, 3};
//    vector<int> nums2 = {1, 2, 3};
//    double median = solution.findMedianSortedArrays(nums1, nums2);

//    string s = "aaabaaaa";
//    string sub = solution.longestPalindrome(s);

//    int num = 1563847412;
//    int reverse_num = solution.reverse(num);

//    BinaryTreeNode *n1 = new BinaryTreeNode(8);
//    BinaryTreeNode *n2 = new BinaryTreeNode(6);
//    BinaryTreeNode *n3 = new BinaryTreeNode(10);
//    BinaryTreeNode *n4 = new BinaryTreeNode(5);
//    BinaryTreeNode *n5 = new BinaryTreeNode(7);
//    BinaryTreeNode *n6 = new BinaryTreeNode(9);
//    BinaryTreeNode *n7 = new BinaryTreeNode(11);
//
//    n1->left = n2, n1->right = n3;
//    n2->left = n4, n2->right = n5;
//    n3->left = n6, n3->right = n7;
//
//    bunSolution.mirrorBinaryTree(n1);
//
//    vector<int> nums = {1, 2, 3, 4};

    // bunSolution.permutation(nums);

    // bunSolution.eight_queens();
//    string str;
//    cin >> str;
//    string result = stringEncoding(str);
//    cout << result;
    */

    int N;
    int D;
    cin >> N;
    cin >> D;
    vector<vector<int>> nums(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> nums[i][j];

    int max = maxSummary(N, D, nums);

    cout << max;

    return 0;
}
