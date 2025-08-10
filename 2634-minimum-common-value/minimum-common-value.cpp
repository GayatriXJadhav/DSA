class Solution {
public:
    int n1,n2;
    int twoPointer(vector<int>&nums1,vector<int>&nums2){
        int i=0,j=0;
        for(;i<n1 && j<n2;){
            int x=nums1[i],y=nums2[j];
            if(x==y) return x;
            else if(x>y) j++;
            else i++;
        }
        return -1;

    }
    int binarySearch(vector<int>&nums1 ,vector<int>&nums2){
        int j=0;
        for(int i=0;i<n1;i++){

        int x=nums1[i];
        j=lower_bound(nums2.begin()+j,nums2.end(),x)-nums2.begin();
        if(j==n2) return -1;
        if(x==nums2[j]) return x;
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size();
        n2=nums2.size();
        if(n1 + n2 <=min(n1*log2(n2),n2*log2(n1))) return twoPointer(nums1,nums2);
        else if(n1>n2){
            swap(n1,n2);
            return binarySearch(nums2,nums1);
        }
        else {
            return binarySearch(nums1,nums2);
        }
        return -1;

    }
};