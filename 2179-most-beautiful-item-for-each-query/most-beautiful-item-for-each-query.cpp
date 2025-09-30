class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>prices,maxB;
        int maxBeauty=0;
        for(auto &it:items){
            int price=it[0],beauty=it[1];
            maxBeauty=max(maxBeauty,beauty);
            if(prices.empty() || prices.back()!=price){
                prices.push_back(price);
                maxB.push_back(maxBeauty);
            }
            else{
                maxB.back()=maxBeauty;
            }
        }
        
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int query=queries[i];
            int idx=upper_bound(prices.begin(),prices.end(),query)-prices.begin()-1;
            if(idx>=0){
                ans.push_back(maxB[idx]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};