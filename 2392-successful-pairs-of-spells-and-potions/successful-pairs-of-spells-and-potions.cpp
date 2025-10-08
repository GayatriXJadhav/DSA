class Solution {
public:
    int binarySearch(long long s, vector<int>& potions, long long success){
        long long low=0;
        long long high=potions.size()-1;
        int ans=0;
        
        while(low<=high){
            long long mid=(low + high)/2;
            if(s*potions[mid]>=success){
                ans=potions.size()-mid;
                 high=mid-1;
                 
            }
            else{
                 low=mid+1;
            
             
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int n=spells.size();
      int m=potions.size();
      sort(potions.begin(),potions.end());
      vector<int>res;
      for(int i=0;i<n;i++){
        int ans=binarySearch(spells[i],potions,success);
        res.push_back(ans);
      }
      return res;
    }
};