//
// Created by bunguang on 2018/3/17.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string expressionResult(string str) {
    if (str.size() > 5) {
        string sub = str.substr(1, str.size() - 2);
        int count = 0;
        string sub_f;
        string sub_l;
        string sub_r;
        string t_str;
        for (int i = 0; i < sub.size(); i++) {
            char tmpChar = sub[i];
            if (tmpChar == '(') count++;
            if (tmpChar == ')') count--;
            if (count == 0 && tmpChar == '!') {
                sub_f = sub.substr(i + 1);
                string tmp_str_f = expressionResult(sub_f);
                t_str = "(";
                t_str.insert(t_str.end(), tmpChar);
                t_str = t_str + tmp_str_f + ")";
                return expressionResult(t_str);
            }
            if (count == 0 && (tmpChar == '|' || tmpChar == '&')) {
                sub_l = sub.substr(0, i);
                sub_r = sub.substr(i + 1);
                string tmp_str_l = expressionResult(sub_l);
                string tmp_str_r = expressionResult(sub_r);
                t_str = "(" + tmp_str_l;
                t_str.insert(t_str.end(), tmpChar);
                t_str = t_str + tmp_str_r + ")";
                return expressionResult(t_str);
            }
        }
    }

    if (str.size() == 1) return str;
    if (str.size() == 4) {
        if (str[2] == '0') return "1";
        else if (str[2] == '1') return "0";
    }
    if (str.size() == 5) {
        if (str[2] == '|') {
            if (str[1] == '1' || str[3] == '1') return "1";
            else return "0";
        } else if (str[2] == '&') {
            if (str[1] == '0' || str[3] == '0') return "0";
            else return "1";
        }
    }


}

int main() {
    int str_size;
    cin >> str_size;
    for (int i = 0; i < str_size; i++) {
        string tmpStr;
        cin >> tmpStr;
        // string sub = tmpStr.substr(1, tmpStr.size() - 1);
        string result = expressionResult(tmpStr);
        cout << result << endl;
        // 这里可能要考虑释放一下string变量的值, 内存有限制
    }

    return 0;
}