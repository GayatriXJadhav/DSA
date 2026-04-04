class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=accumulate(apple.begin(),apple.end(),0);
        int cnt=0;
        while(sum>0 ){
            sum-=capacity[cnt++];
        }
        return cnt;
        
        
    }
};