class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int ans=0;
        int low=0;
        int high=citations.size()-1;
        while(low<=high){
            int mid=(low + high)/2;
            if(citations[mid]>=n-mid){
               
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return n-low;
    }
};