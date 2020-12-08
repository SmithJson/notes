/**
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * 运行你的函数后，矩阵变为：
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * 解释:
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
 * 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 */

class Solution {
public:
    int n, m;
    void solve(vector<vector<char>>& board) {
        if (!board.empty() && !board[0].empty()) {
            n = board.size();
            m = board[0].size();

            for (int i = 0; i < n; i++) {
                if (board[i][0] == 'O') dfs(board, i, 0);
                if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
            }

            for (int i = 0; i < m; i++) {
                if (board[0][i] == 'O') dfs(board, 0, i);
                if (board[n - 1][i] == 'O') dfs(board, n - 1, i);
            }

            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int sr, int sc) {
        if (sr >= 0 && sr < n && sc >= 0 && sc < m && board[sr][sc] == 'O') {
            board[sr][sc] = 'Y';
            int dx[4] = {0, 1, 0, -1},
                dy[4] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int x = sr + dx[i],
                    y = sc + dy[i];
                dfs(board, x, y);
            }
        }
    }
};
