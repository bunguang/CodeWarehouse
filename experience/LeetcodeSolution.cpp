//
// This file is for the solution of leetcode.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> find_all(string s, char c) {
    vector<int> index;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c) index.insert(index.end(), i);
    return index;
}

bool update_index(string s, char c, vector<int> &index) {
    vector<int> index_new;
    bool flag = false;
    for (int i = 0; i < index.size(); i++) {
        if (index[i] == s.size() - 1) continue;
        if (s[index[i] + 1] == c) {
            index_new.insert(index_new.end(), index[i] + 1);
            flag = true;
        }
    }
    index = index_new;
    return flag;
}

bool isPalindromeString(string s) {
    int size = s.size();
    bool flag = true;
    for (int i = 0; i < size / 2; i++) {
        if (s[i] != s[size - 1 - i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

vector<int> reverse_ten_to_two(int num) {
    vector<int> two_num;
    if (num == 0) two_num = {0};
    int n = 0;
    while (num != 0) {
        n = num % 2;
        num = num / 2;
        two_num.insert(two_num.end(), n);
    }
    return two_num;
}

class LeetcodeSolution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int num1, num2;
        int array_size = nums.size();
        vector<int> result = {0, 0};
        for (int i = 0; i < array_size; i++) {
            num1 = nums[i];
            for (int j = i + 1; j < array_size; j++) {
                num2 = nums[j];
                if (num1 + num2 == target) {
                    result = {i, j};
                    return result;
                }
            }
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int num1, num2, num3;
        int data_size = nums.size();
        vector<vector<int>> result;
        vector<int> result_element;
        unordered_map<int, int> bunMap;
        for (int i = 0; i < nums.size(); i++) {
            bunMap[nums[i]] = i;
        }
        auto iter = bunMap.end();

        for (int i = 0; i < data_size - 2; i++) {
            num1 = nums[i];
            if (num1 > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < data_size - 1; j++) {
                num2 = nums[j];
                if (num1 + num2 > 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (abs(num1 + num2) > nums[data_size - 1]) continue;
                iter = bunMap.find(abs(num1 + num2));
                if (iter != bunMap.end() && iter->second > j) {
                    int num3_index = iter->second;
                    num3 = nums[num3_index];
                    result_element = {num1, num2, num3};
                    result.push_back(result_element);
                }
            }
        }
        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = new ListNode(0);
        int update = 0;
        int sum = 0;
        int result = 0;
        while (l1 != NULL || l2 != NULL || update == 1) {
            if (l1 != NULL && l2 != NULL) {
                sum = l1->val + l2->val + update;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 == NULL && l2 != NULL) {
                sum = l2->val + update;
                l2 = l2->next;
            } else if (l2 == NULL && l1 != NULL) {
                sum = l1->val + update;
                l1 = l1->next;
            } else if (l1 == NULL && l2 == NULL) {
                sum = 1;
            }
            result = sum % 10;
            update = sum / 10;
            ListNode *tmp_node = new ListNode(result);
            ListNode *tail = l3;
            while (tail->next != NULL) tail = tail->next;
            tail->next = tmp_node;
        }
        return l3->next;
    }

    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        int strs_size = strs.size();
        if (strs_size == 0) return prefix;
        int min_len_index = 0;
        int min_len = 10000000;
        for (int i = 0; i < strs_size; i++) {
            if (strs[i].size() < min_len) {
                min_len = strs[i].size();
                min_len_index = i;
            }
        }
        int flag = 1;
        for (int i = 0; i < min_len; i++) {
            char tmp = strs[min_len_index][i];
            for (int j = 0; j < strs_size; j++) {
                if (tmp != strs[j][i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) prefix = prefix + tmp;
            else break;
        }
        return prefix;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int num1 = x;
        int len = 1;
        int n = 1;
        while (num1 > 9) {
            num1 = num1 / 10;
            len = len * 10;
            n++;
        }
        n = n / 2;
        num1 = x;
        int num2 = x;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int tmp1 = (num1 / len) % 10;
            int tmp2 = num2 % 10;
            if (tmp1 != tmp2) {
                flag = false;
                break;
            }
            len = len / 10;
            num2 = num2 / 10;
        }
        return flag;
    }

    int reverse(int x) {
        int flag = 1;
        if (x < 0) flag = -1;
        if (x < INT32_MIN + 1) return 0;
        if (x > INT32_MAX - 1) return 0;
        int num1 = abs(x);
        int len1 = 1;
        int size = 1;
        while (num1 > 9) {
            num1 = num1 / 10;
            len1 = len1 * 10;
            size++;
        }
        int n = size / 2;
        num1 = abs(x);
        int num2 = abs(x);
        unsigned int sum = 0;
        int len2 = 1;
        int maxInt = INT32_MAX;
        int maxLen = 1000000000;
        int over_flag = 1;
        for (int i = 0; i < n; i++) {
            int tmp1 = (num1 / len1) % 10;
            int tmp2 = num2 % 10;
            int tmpm = (maxInt / maxLen) % 10;
            if (maxLen == len1 && tmp2 < tmpm) over_flag = 0;
            if (maxLen == len1 && tmp2 > tmpm && over_flag == 1) return 0;
            sum = sum + tmp1 * len2 + tmp2 * len1;
            len1 = len1 / 10;
            maxLen = maxLen / 10;
            num2 = num2 / 10;
            len2 = len2 * 10;
        }
        if (size % 2 == 1) {
            sum = sum + (num2 % 10) * len1;
        }
        if (sum > INT32_MAX) return 0;
        return sum * flag;
    }

    int romanToInt(string s) {
        int size = s.size();
        int num = 0;
        int len = 1;
        int tmp = 0;
        int tmp_last = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (s[i] == 'I') tmp = 1;
            else if (s[i] == 'X') tmp = 10;
            else if (s[i] == 'C') tmp = 100;
            else if (s[i] == 'M') tmp = 1000;
            else if (s[i] == 'V') tmp = 5;
            else if (s[i] == 'L') tmp = 50;
            else if (s[i] == 'D') tmp = 500;
            if ((tmp == 1 || tmp == 10 || tmp == 100) && tmp_last > tmp) num = num - tmp;
            else num = num + tmp;
            tmp_last = tmp;
        }
        return num;
    }

    string intToRoman(int num) {
        int base[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string bunStr = "";
        while (num > 0) {
            for (int i = 0; i < 13; i++) {
                if (num >= base[i]) {
                    bunStr = bunStr + str[i];
                    num = num - base[i];
                    break;
                }
            }
        }
        return bunStr;
    }

    int lengthOfLongestSubstring(string s) {
        string substr = "";
        int tmpLength = 0;
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (substr.find_last_of(s[i]) == substr.npos) {
                substr = substr + s[i];
                tmpLength = tmpLength + 1;
                if (tmpLength > maxLength) maxLength = tmpLength;
            } else {
                int index = substr.find_last_of(s[i]);
                string tmpstr = substr.substr(index + 1);
                substr = tmpstr + s[i];
                tmpLength = tmpstr.size() + 1;
            }
        }
        return maxLength;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        double median1 = 0, median2 = 0;
        if (len1 == 0) {
            median1 = nums2[(len2 - 1) / 2];
            median2 = nums2[len2 / 2];
            return (median1 + median2) / 2.0;
        } else if (len2 == 0) {
            median1 = nums1[(len1 - 1) / 2];
            median2 = nums1[len1 / 2];
            return (median1 + median2) / 2.0;
        }
        int len_sum = len1 + len2;
        int target1 = (len_sum - 1) / 2, target2 = len_sum / 2;
        int count = 0;
        int index1 = 0, index2 = 0;
        while (count <= target2) {
            if ((nums1[index1] >= nums2[index2]) && index2 <= len2 - 1) {
                if (count == target1) median1 = nums2[index2];
                if (count == target2) median2 = nums2[index2];
                index2++;
                count++;
            } else if ((nums1[index1] >= nums2[index2]) && index2 > len2 - 1) {
                if (count == target1) median1 = nums1[index1];
                if (count == target2) median2 = nums1[index1];
                index1++;
                count++;
            } else if ((nums1[index1] < nums2[index2]) && index1 <= len1 - 1) {
                if (count == target1) median1 = nums1[index1];
                if (count == target2) median2 = nums1[index1];
                index1++;
                count++;
            } else if ((nums1[index1] < nums2[index2]) && index1 > len1 - 1) {
                if (count == target1) median1 = nums2[index2];
                if (count == target2) median2 = nums2[index2];
                index2++;
                count++;
            }
        }
        double median = (median1 + median2) / 2;
        return median;
    }

    string longestPalindrome(string s) {
        int strSize = s.size();
        if (strSize == 0) return "";
        string subString;
        subString = s[0];
        int maxLength = 1;
        char tmpChar;
        for (int i = 0; i < strSize; i++) {
            if (maxLength >= (strSize - i)) break;
            tmpChar = s[i];
            int this_tmp_index = strSize - 1;
            int next_tmp_index = s.find_last_of(tmpChar, this_tmp_index);
            while (next_tmp_index > i) {
                if (maxLength >= (next_tmp_index + 1 - i)) break;
                string tmpString = s.substr(i, next_tmp_index + 1 - i);
                if (isPalindromeString(tmpString)) {
                    int tmpLength = tmpString.size();
                    if (tmpLength > maxLength) {
                        subString = tmpString;
                        maxLength = tmpLength;
                    }
                    break;
                } else {
                    this_tmp_index = next_tmp_index;
                    next_tmp_index = s.find_last_of(tmpChar, this_tmp_index - 1);
                }
            }
        }
        return subString;
    }

    vector<string> longestCommonSubstring(vector<string> &strs) {
        int vector_size = strs.size();
        int minLength = 10000000;
        int minIndex = 0;
        for (int i = 0; i < vector_size; i++) {
            if (strs[i].size() < minLength) {
                minIndex = i;
                minLength = strs[i].size();
            }
        }

        vector<string> lcSubstring;

        int max_str_length = 0;
        for (int i = 0; i < minLength; i++) {
            vector<vector<int>> indexRecord(vector_size);
            char tmpChar = strs[minIndex][i];
            string tmpSubstring;
            int tmp_str_length = 0;

            bool flag1 = true;
            for (int j = 0; j < strs.size(); j++) {
                vector<int> tmpIndex = find_all(strs[j], tmpChar);
                if (tmpIndex.size() == 0) {
                    flag1 = false;
                    break;
                }
                indexRecord[j] = tmpIndex;
            }
            if (flag1 == false) continue;

            tmpSubstring = tmpChar;
            tmp_str_length = 1;
            if (tmp_str_length > max_str_length) {
                max_str_length = tmp_str_length;
                lcSubstring.clear();
                lcSubstring.insert(lcSubstring.end(), tmpSubstring);
            } else if (tmp_str_length == max_str_length)
                if (find(lcSubstring.begin(), lcSubstring.end(), tmpSubstring) == lcSubstring.end())
                    lcSubstring.insert(lcSubstring.end(), tmpSubstring);

            bool flag2 = true;
            for (int j = i + 1; j < minLength; j++) {
                tmpChar = strs[minIndex][j];
                for (int k = 0; k < strs.size(); k++) {
                    flag2 = update_index(strs[k], tmpChar, indexRecord[k]);
                    if (flag2 == false) break;
                }
                if (flag2 == false) break;
                tmpSubstring = tmpSubstring + tmpChar;
                tmp_str_length = tmp_str_length + 1;
                if (tmp_str_length > max_str_length) {
                    max_str_length = tmp_str_length;
                    lcSubstring.clear();
                    lcSubstring.insert(lcSubstring.end(), tmpSubstring);
                } else if (tmp_str_length == max_str_length)
                    if (find(lcSubstring.begin(), lcSubstring.end(), tmpSubstring) == lcSubstring.end())
                        lcSubstring.insert(lcSubstring.end(), tmpSubstring);
            }
        }
        return lcSubstring;
    }

    int numJewelsInStones(string J, string S) {
        auto j_size = J.size();
        auto s_size = S.size();
        int count = 0;
        for (int j = 0; j < j_size; j++) {
            char tmpChar = J[j];
            for (int s = 0; s < s_size; s++)
                if (S[s] == tmpChar) count++;
        }
        return count;
    }

    int numJewelsInStones_map(string J, string S) {
        auto j_size = J.size();
        auto s_size = S.size();
        int count = 0;
        unordered_map<char, int> bunMap;
        for (int j = 0; j < j_size; j++) bunMap[J[j]] = j;
        for (int s = 0; s < s_size; s++)
            if (bunMap.find(S[s]) != bunMap.end()) count++;
        return count;
    }

    int hammingDistance(int x, int y) {
        vector<int> num1 = reverse_ten_to_two(x);
        vector<int> num2 = reverse_ten_to_two(y);
        auto length1 = num1.size();
        auto length2 = num2.size();
        if (length1 > length2) {
            int diff = length1 - length2;
            length2 = length1;
            for (int i = 0; i < diff; i++) num2.insert(num2.end(), 0);
        } else if (length1 < length2) {
            int diff = length2 - length1;
            length1 = length2;
            for (int i = 0; i < diff; i++) num1.insert(num1.end(), 0);
        }
        int distance = 0;
        for (int i = 0; i < length1; i++) distance = distance + abs(num1[i] - num2[i]);
        return distance;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *checkpoint1 = l1;
        ListNode *checkpoint2 = l2;
        ListNode *l3 = new ListNode(0);
        ListNode *tail = l3;
        while (checkpoint1 != NULL || checkpoint2 != NULL) {
            ListNode *newNode;
            if (checkpoint1 == NULL) {
                newNode = new ListNode(checkpoint2->val);
                checkpoint2 = checkpoint2->next;
            } else if (checkpoint2 == NULL) {
                newNode = new ListNode(checkpoint1->val);
                checkpoint1 = checkpoint1->next;
            } else {
                if (checkpoint1->val > checkpoint2->val) {
                    newNode = new ListNode(checkpoint2->val);
                    checkpoint2 = checkpoint2->next;
                } else {
                    newNode = new ListNode(checkpoint1->val);
                    checkpoint1 = checkpoint1->next;
                }
            }
            tail->next = newNode;
            tail = newNode;
        }
        return l3->next;
    }
};
