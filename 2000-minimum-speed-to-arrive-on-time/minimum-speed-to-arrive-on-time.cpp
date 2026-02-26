class Solution {
public:
    bool canWeTravel(vector<int>& dist, long long speed,double hour){
      double cnt=0;
        for(int i=0;i<dist.size();i++){
           double time=(double)dist[i]/speed;
           if(i!=dist.size()-1) cnt+=ceil(time);
           else cnt+=time;
        }
        if(cnt <=hour) return true;
        else return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour< dist.size()- 1) return -1;
        long long  low=1, high=1e7;
        long long ans=-1;
        while(low <= high){
            long long mid=(low + high)/2;
            if(canWeTravel(dist,mid,hour)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};