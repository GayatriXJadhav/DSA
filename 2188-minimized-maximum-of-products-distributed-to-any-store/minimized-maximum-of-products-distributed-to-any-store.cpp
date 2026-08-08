class Solution {
public:
    bool possible(vector<int>& arr,int x, int n){
        int stores_needed=0;
        for(int i=0;i<arr.size();i++){
            stores_needed += ceil((double)arr[i]/x);
        }
        if(stores_needed>n) return false;
        else return true;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        long long low=1;
        long long high=*max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid=(low + high)/2;
            if(possible(arr,mid,n)==true) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};