class Solution {
public:
    string removeKdigits(string s, int k) {
        // int n=s.size();
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>s[i]-'0')
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
           
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
            if(res.empty()) return "0";
        }
         

        reverse(res.begin(),res.end());
       
        return res;
    }

};