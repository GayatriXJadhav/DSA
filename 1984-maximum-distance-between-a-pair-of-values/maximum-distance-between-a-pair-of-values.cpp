class Solution {
public:
    void binarySearch(int i,vector<int>&nums1,vector<int>&nums2,long long &maxDist){
        long long low=i,high=nums2.size()-1;
        
        while(low<=high){
            long long mid=(low + high)/2;
            if(mid>=i && nums2[mid]>=nums1[i]){
               maxDist=mid-i;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
      
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<long long>distance;

        for(int i=0;i<nums1.size();i++){
            long long maxDist=-1;
            binarySearch(i,nums1,nums2,maxDist);
            distance.push_back(maxDist);
        }
        long long maxi=0;
        for(auto it:distance){
            maxi=max(maxi,it);
        }
        return maxi;
    }
};