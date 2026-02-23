class Solution {
public:
    bool f1(vector<int>& ranks, int cars, long long mid) {
        long long carsM = 0;

        for (int i = 0; i < ranks.size(); i++) {
            carsM += (long long)sqrt((double)mid / ranks[i]);
            if (carsM >= cars)
                return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long max_rank = *max_element(ranks.begin(), ranks.end());
        long long low = 1, high = max_rank * (long long)cars * cars;
        long long ans = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (f1(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};