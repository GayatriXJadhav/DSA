class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                zeros++;
        }

        for (int i = n - 1; i >= 0; i--) {
            int j = i + zeros;

            if (j < n)
                arr[j] = arr[i];

            if (arr[i] == 0) {
                zeros--;
                if (i + zeros < n)
                    arr[i + zeros] = 0;
            }
        }
    }
};