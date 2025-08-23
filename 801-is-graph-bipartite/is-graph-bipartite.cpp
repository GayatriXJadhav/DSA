class Solution {
public:
    bool check(int startNode,int V,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(startNode);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int totalNodes=graph.size();
       vector<int>color(totalNodes,-1);
       for(int i=0;i<totalNodes;i++){
        if(color[i]==-1){

         if(check(i,totalNodes,graph,color)==false) return false;
        }
       }
  return true;
    }
};