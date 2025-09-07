class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st;
        int n=candyType.size();
    
        int half=n/2;
        for(int i=0;i<n;i++){
           if(st.size()==half) return st.size();
           st.insert(candyType[i]);
        }
        return st.size();
    }
};