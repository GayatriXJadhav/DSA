class Solution {
public:
    bool fn(vector<int>& candies, long long k,long long mid){
        long long cnt=0;
        for(int i=0;i<candies.size();i++){
            cnt+=candies[i]/mid;
        }
        if(cnt>=k) {
            return true;
        }
        else {
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if(sum<k) return 0;
        long long  low=1 ;
        long long    high=*max_element(candies.begin(),candies.end());
       int ans=0;
        while(low<=high){
            long long  mid=(low + high)/2;
            if(fn(candies,k,mid)==true){
               ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};