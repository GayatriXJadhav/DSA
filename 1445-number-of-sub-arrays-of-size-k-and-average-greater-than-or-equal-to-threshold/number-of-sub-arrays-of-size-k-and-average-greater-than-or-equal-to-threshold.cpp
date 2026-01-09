class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0,r=0,cnt=0,len=0,sum=0,t=0;
        while(r<arr.size()){
            sum+=arr[r];
            len=r-l+1;
            while(len==k){
                t=sum/k;
                if(t>=threshold) cnt++;
                len--;
                sum-=arr[l];
                l++;
            }
            r++;
        }
        return cnt;
      
    }
};