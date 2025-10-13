class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>result;
        result.push_back(words[0]);
        string prev=result[0];
        
        for(int i=1;i<words.size();i++){
            string newW=words[i];
            sort(prev.begin(),prev.end());
            sort(words[i].begin(),words[i].end());
            if(prev!=words[i]){
                result.push_back(newW);
            }
            
            prev=words[i];
        }
        return result;
    }
};