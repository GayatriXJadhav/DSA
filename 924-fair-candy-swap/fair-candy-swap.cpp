class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int s1=0,s2=0;
        for(int i=0;i<a.size();i++){
            s1+=a[i];
        }
         for(int i=0;i<b.size();i++){
            s2+=b[i];
        }
        map<int,int>mpp;
        for(int i=0;i<b.size();i++){
            mpp[b[i]]++;
        }
     
        for(int i=0;i<a.size();i++){
            int x=a[i];
           
            int y=x + (s2-s1)/2;
            if(mpp.find(y)!=mpp.end()){
               return {x,y};
            }
        }
        return {};
    }
};