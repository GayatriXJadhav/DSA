class Solution {
public:
    int binarySearch(vector<long long>&prefix, long long &x,int n){
        
        long long low=0,high=n-1;
        long long ans=0;
        while(low<=high){
            int mid=(low + high)/2;
            if(prefix[mid] > x) {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }


        }
        return ans;
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        int n=chalk.size();
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        long long remainingChalk=k % sum;
        vector<long long>prefix(n);
        prefix[0]=chalk[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1] + chalk[i];
        }
        int ans=binarySearch(prefix,remainingChalk,n);
        return ans;
    }
};