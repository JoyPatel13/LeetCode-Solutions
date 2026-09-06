class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1)
            return grid[0][0];

        vector<vector<vector<vector<int>>>> dist(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(4, vector<int>(k + 1, INT_MAX))));

        priority_queue<array<int, 5>, vector<array<int, 5>>, greater<>> pq;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = dr[i], nc = dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            int cost = grid[0][0] + grid[nr][nc];

            if (cost < dist[nr][nc][i][0]) {
                dist[nr][nc][i][0] = cost;
                pq.push({cost, nr, nc, i, 0});
            }
        }

        int ans = INT_MAX;

        while (!pq.empty()) {
            auto [cost, i, j, d, t] = pq.top();

            pq.pop();

            if (cost > dist[i][j][d][t])
                continue;

            if (i == n - 1 && j == m - 1) {
                ans = min(ans, cost);
                continue;
            }

            for (int nd = 0; nd < 4; nd++) {
                int nr = i + dr[nd], nc = j + dc[nd];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                int nt = t + (nd != d ? 1 : 0);
                if (nt > k)
                    continue;

                int ncost = cost + grid[nr][nc];
                if (ncost < dist[nr][nc][nd][nt]) {
                    dist[nr][nc][nd][nt] = ncost;
                    pq.push({ncost, nr, nc, nd, nt});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};