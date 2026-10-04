class Solution {
public:
    bool canPick(int diff, vector<int>&price, int k){
        int cnt=1;
       int last_picked=price[0];
      
        for(int i=0;i<price.size();i++){
            if(price[i]-last_picked>=diff)
            {
                cnt++;
                last_picked=price[i];
                if(cnt==k) return true;

            }
            
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low=0;
        int n=price.size();
        int high=price[n-1] - price[0];
        while(low<=high){
            int mid=(low  + high)/2;
            if(canPick(mid, price, k)){
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }

};