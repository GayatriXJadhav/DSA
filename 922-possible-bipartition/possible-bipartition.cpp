class Solution {
public:
    bool bfs(int start, vector<vector<int>>& dislikes, vector<int>& color,
             vector<vector<int>>& adjLs) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adjLs[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjLs(n + 1);
        for (auto& edge : dislikes) {
            int u = edge[0];
            int v = edge[1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {

                if (!bfs(i, dislikes, color, adjLs)) {
                    return false;
                }
            }
        }
        return true;
    }
};