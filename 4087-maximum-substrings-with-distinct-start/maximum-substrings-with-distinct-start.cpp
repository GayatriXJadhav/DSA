class Solution {
public:
    int maxDistinct(string s) {
      int n=s.size();
      unordered_map<char,int>mpp;
      for(int i=0;i<n;i++){
      mpp[s[i]]++;
      }
      int maxSum=0;
      maxSum=mpp.size();
      return maxSum;
    }
};