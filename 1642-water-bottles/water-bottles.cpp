class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
       
         int cnt=0;
         int quotient;
         int remainder;
         cnt+=numBottles;
         
        while(numBottles>=numExchange){
        
        quotient=numBottles/numExchange;
         remainder=numBottles%numExchange;
        cnt+=quotient;
        numBottles=quotient + remainder;
        }
        return cnt;
    }
};