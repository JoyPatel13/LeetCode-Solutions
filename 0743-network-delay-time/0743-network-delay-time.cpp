class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        //{distance , {node , time}};
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>q;
        q.push({0, k});
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int node = it.second;

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    q.push({dis + edW, adjNode});
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1; 
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};