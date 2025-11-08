class Solution {
public:
    bool canwePlace(vector<int>& position, int mid,int m){
        int cnt=1, last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=mid){
                cnt++;
                last=position[i];
            }
        }
        if(cnt>=m) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
       int low=1;
       int  high=*max_element(position.begin(),position.end());
       while(low<=high){
        int mid= (low  + high)/2;
        if(canwePlace(position,mid,m)==true){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
       }
       return high;
    }
};