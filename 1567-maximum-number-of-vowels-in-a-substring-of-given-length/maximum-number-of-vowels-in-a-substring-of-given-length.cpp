class Solution {
public:
    int maxVowels(string s, int k) {
        long long l = 0, r = 0, len = 0, maxCnt = 0;
        unordered_map<char, int> mpp;
        while (r < s.size()) {
            len = r - l + 1;

            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' ||
                s[r] == 'u') {
                mpp[s[r]]++;
            }
            if (len == k) {

                long long cnt = 0;
                for (auto& it : mpp) {
                    cnt += it.second;
                }

                maxCnt = max(maxCnt, cnt);
                len--;
                if(mpp[s[l]]) mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return maxCnt;
    }
};