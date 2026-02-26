class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({difficulty[i],profit[i]});

        }
        sort(jobs.begin(),jobs.end());
        for(int i=1;i<n;i++){
            jobs[i].second=max(jobs[i].second,jobs[i-1].second);
        }
        int total=0;
        for(int A:worker){
            int low=0,high=n-1;
            int best=-1;
            while(low<=high){
                int mid=(low + high)/2;
                if(jobs[mid].first<=A){
                    best=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(best !=-1){
                total+=jobs[best].second;
            }
        }
        return total;
    }
};