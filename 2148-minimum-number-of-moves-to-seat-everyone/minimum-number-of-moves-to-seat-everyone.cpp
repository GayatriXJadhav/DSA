class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int i=0,j=0,cnt=0;
        for(int i=0;i<students.size();i++){
            int move=abs(students[i]-seats[j]);
            cnt+=move;
            j++;
        }
        return cnt;
    }
};