class Solution {
public:
    bool isConsecutiveSorted(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i + 1] != nums[i] + 1)
                return false;
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l = 0, r = 0, len = 0;
        vector<int> res;
        while (r < nums.size()) {
            len = r - l + 1;
            while (len == k) {
                int maxele = 0;
                if (isConsecutiveSorted(nums, l, k) == true) {
                    maxele = *max_element(nums.begin() + l, nums.begin() + r + 1);
                } else {
                    maxele = -1;
                }
                res.push_back(maxele);
                len--;
                l++;
            }
            r++;
        }
        return res;
    
}
}
;