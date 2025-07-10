/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n >= k + maxPts - 1)
            return 1.0;
        vector<double> dp(n + maxPts + 1, 0.0);
        for (int i = k; i <= n; ++i)
            dp[i] = 1.0;
        double windowSum = n - k + 1;
        for (int i = k - 1; i >= 0; --i)
        {
            dp[i] = windowSum / maxPts;
            windowSum += dp[i] - dp[i + maxPts];
        }
        return dp[0];
    }
};
// @lc code=end

// 題意理解
// 你要從 0 分開始，每次隨機加 1~maxPts 分，直到分數達到 k 以上就停止。問你最後分數不超過 n 的機率是多少。

// 狀態設計
// 設 dp[x] 表示「目前分數為 x 時，最終分數不超過 n 的機率」。

// 邊界條件

// 如果 x >= k，遊戲結束：
// 若 x <= n，dp[x] = 1（成功）
// 若 x > n，dp[x] = 0（失敗）
// 如果 x < k，還可以繼續抽牌。
// 狀態轉移方程式

// dp[x] = (dp[x+1] + dp[x+2] + ... + dp[x+maxPts]) / maxPts
// 代表你下一步可能抽到 1~maxPts，每種情況等機率。
// 滑動視窗優化

// 直接計算 dp[x+1]~dp[x+maxPts] 的和，然後每次往前移動時加一個減一個，避免重複加總。
// 程式實作

// 先把所有 x >= k 且 x <= n 的 dp[x] 設為 1。
// 從 k-1 開始往前推 dp[x]。
// 回傳 dp[0]。