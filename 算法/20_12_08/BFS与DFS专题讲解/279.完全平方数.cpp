/**
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 示例 1:
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 *
 * 示例 2:
 * 输入: n = 13
 * 输出: 
 * 解释: 13 = 4 + 9.
 * */
// BFS
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<int> dist(n + 1, n + 1);
        q.push(0);
        dist[0] = 0;
        while (q.size())
        {
            int t = q.front();
            q.pop();
            if (t == n) return dist[t];
            for (int i = 1; i * i + t <= n; i++) 
            {
                int j = i * i + t;
                if (dist[j] > dist[t] + 1)
                {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                }
            }
        }
        return 0;
    }
};

// DP
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <=n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
