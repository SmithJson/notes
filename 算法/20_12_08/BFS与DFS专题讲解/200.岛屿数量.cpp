/**
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 * 示例 1：
 * 输入：grid = [
 *	["1","1","1","1","0"],
 *	["1","1","0","1","0"],
 *	["1","1","0","0","0"],
 *	["0","0","0","0","0"]
 *	]
 *	输出：1
 *
 * 示例 2：
 * 输入：grid = [
 *	["1","1","0","0","0"],
 *	["1","1","0","0","0"],
 *	["0","0","1","0","0"],
 *	["0","0","0","1","1"]
 * ]
 * 输出：3
 * */

/**
 * DFS
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if (!grid || !grid.length || !grid[0].length) return 0;
    let n = grid.length;
    let m = grid[0].length;
    let res = 0;
    // 遍历一遍二维网格
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === "1") {
                res++;
                dfs(grid, i, j, n, m);
            }
        }
    }
    return res;
};

function dfs(grid, sr, sc, n, m) {
    let dx = [0, 1, 0, -1];
    let dy = [-1, 0, 1, 0];
    grid[sr][sc] = "0";
    for (let i = 0; i < 4; i++) {
        let x = sr + dx[i];
        let y = sc + dy[i];
        if (x >= 0 && x < n && y >=0 && y < m && grid[x][y] === "1") 
            dfs(grid, x, y, n, m);
    }
}
