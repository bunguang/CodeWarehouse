#include <map>
#include <vector>
#include <iostream>
using namespace std;
map<int, vector<int>> dict;

void init()
{
    vector<int> v1 = { 0, 0, 1, 0, 0, 1, 0 };
    vector<int> v2 = { 1, 0, 1, 1, 1, 0, 1 };
    vector<int> v3 = { 1, 0, 1, 1, 0, 1, 1 };
    vector<int> v4 = { 0, 1, 1, 1, 0, 1, 0 };
    vector<int> v5 = { 1, 1, 0, 1, 0, 1, 1 };
    vector<int> v6 = { 1, 1, 0, 1, 1, 1, 1 };
    vector<int> v7 = { 1, 0, 1, 0, 0, 1, 0 };
    vector<int> v8 = { 1, 1, 1, 1, 1, 1, 1 };
    vector<int> v9 = { 1, 1, 1, 1, 0, 1, 1 };
    vector<int> v0 = { 1, 1, 1, 0, 1, 1, 1 };
    dict[0] = v0;
    dict[1] = v1;
    dict[2] = v2;
    dict[3] = v3;
    dict[4] = v4;
    dict[5] = v5;
    dict[6] = v6;
    dict[7] = v7;
    dict[8] = v8;
    dict[9] = v9;
}

void helper(vector<vector<int>> &leds, int pos, int num, int N, int &result)
{
    if (pos >= leds.size())
    {
        if (num < N) result += 1;
        return;
    }
    for (int i = 0; i <= 9; i++)
        //遍历从0到9这9个数
    {
        bool isOk = true;
        for (int j = 0; j < leds[pos].size(); j++)
        {
            int led = leds[pos][j];
            //led表示必须亮的二极管  
            if (dict[i][led - 1] == 0)
            {
                isOk = false;
                break;
            }
        }
        if (isOk)
            //如果这个数可以被表示就以此为基础确定下一位数
            helper(leds, pos + 1, num * 10 + i, N, result);
    }
}

int solve(vector<vector<int>> &leds, int N)
{
    int result = 0;
    helper(leds, 0, 0, N, result);
    return result;
}

//int main()
//{
//    init();
//    int cases = 0;
//    cin >> cases;
//    for (int i = 0; i < cases; i++)
//    {
//        int K, N;
//        cin >> K >> N;
//        vector<vector<int>> leds;
//        cin.get();
//        for (int j = 0; j < K; j++)
//        {
//            char str[100];
//            cin.get(str, 100);
//            vector<int> tmp;
//            for (int i = 0; i < 100; i++)
//            {
//                if (str[i] == ' ') continue;
//                else if (str[i] >= '0' && str[i] <= '9') tmp.push_back(str[i] - '0');
//                else break;
//            }
//            leds.push_back(tmp);
//            cin.get();
//        }
//        cout << solve(leds, N) << endl;
//    }
//}