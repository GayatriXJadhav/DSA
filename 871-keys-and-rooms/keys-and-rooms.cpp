class Solution {
    void dfs(int node, vector<vector<int>>&edges,vector<bool>&vis){
        vis[node]=1;
        for(auto it:edges[node]){
            if(!vis[it]){
                dfs(it,edges,vis);
            }
        }
       
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(0,rooms,vis);
        for(bool v:vis){
            if(!v) return false;
        } 
       
        return true;

    }
};
       
        
       