class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       int low=0;
       int high=letters.size()-1;
       int pos=-1;
       while(low <=high){
        int mid=( low +high)/2;
        if(letters[mid]<=target){
            low=mid+1;
        }
        else {
            high=mid-1;
            pos=high + 1;
        }
       } 
       if(pos==-1){
        return letters[0];
       }
       return letters[pos];
    }
};