/***
 * LeetCode 1034.边界着色
 * 链接：https://leetcode-cn.com/problems/coloring-a-border/
 * 关键点：判断边界！（边界分类：1.网格的边界；2.相邻网格块有不同颜色）
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS
typedef pair<int, int> PII;
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int x, int y, int color) {
        m = g.size(), n = g[0].size();
        int vis[51][51] = {0};
        vector<PII> board;
        queue<PII> q;
        q.push({x, y});
        while (q.size()) {
            auto [a, b] = q.front(); q.pop();
            vis[a][b] = 1;
            bool flag = false;  // 判断是否是边界
            for (int i =0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];
                if (na < 0 || na >= m || nb < 0 || nb >= n || vis[na][nb] || g[na][nb] != g[x][y]) {
                    flag = true;
                    continue;
                }
                if (g[na][nb] == g[x][y]) {
                    q.push({na, nb});
                }
            }
            if (flag) board.push_back({a, b});
        }
        for (auto [a, b] : board) g[a][b] = color;
        return g;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int m, n;
};

