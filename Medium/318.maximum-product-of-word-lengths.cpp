/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    // int maxProduct(vector<string> &words)
    // {
    //     int Max = 0;
    //     int len = words.size();

    //     for (int i = 0; i < len; ++i)
    //     {
    //         for (int j = i + 1; j < len; ++j)
    //         {
    //             if (Check(words[i], words[j]))
    //             {
    //                 int Pro = words[i].size() * words[j].size();
    //                 Max = max(Max, Pro);
    //             }
    //         }
    //     }

    //     return Max;
    // }

    // bool Check(const string &a, const string &b)
    // {
    //     bool ca[26] = {false};
    //     bool cb[26] = {false};

    //     for (auto it : a)
    //     {
    //         ca[it - 'a'] = true;
    //     }

    //     for (auto it : b)
    //     {
    //         cb[it - 'a'] = true;
    //     }

    //     for (int i = 0; i < 26; ++i)
    //     {
    //         if (ca[i] && cb[i])
    //             return false;
    //     }

    //     return true;
    // }

    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> masks(n, 0);
        vector<int> lens(n, 0);

        // 遍歷每一個字串
        for (int i = 0; i < n; ++i)
        {
            int mask = 0; // 初始化 mask，用來記錄這個字串中出現過的字母（用位元表示）

            // 遍歷字串中的每一個字元
            for (char c : words[i])
            {
                // 將對應字母的位置設為 1
                // 例如 'a' -> 第 0 位, 'b' -> 第 1 位, ..., 'z' -> 第 25 位
                mask |= 1 << (c - 'a');
            }

            // 儲存這個字串的字母位元遮罩（bitmask）
            masks[i] = mask;

            // 同時記錄下該字串的長度，方便之後計算乘積
            lens[i] = words[i].size();
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if ((masks[i] & masks[j]) == 0)
                {
                    res = max(res, lens[i] * lens[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
