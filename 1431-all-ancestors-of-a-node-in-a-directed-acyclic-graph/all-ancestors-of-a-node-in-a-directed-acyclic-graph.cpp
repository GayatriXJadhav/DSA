class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // create a adjList
        vector<int> indegree(n, 0);
       vector< vector<int> >adj(n);
        for (auto& it : edges) {
            int f = it[0];
            int t = it[1];
            adj[it[0]].push_back(it[1]);
            indegree[t]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<set<int>> ancestors(n);
       
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                indegree[it]--;
               for(int anc:ancestors[node]){
                ancestors[it].insert(anc);
               }
               ancestors[it].insert(node);
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        vector<vector<int>>ans;
        for(auto &it:ancestors){
            vector<int>temp(it.begin(),it.end()); //convert set to vector
            ans.push_back(temp);
        }
        
        return ans;
    }
};