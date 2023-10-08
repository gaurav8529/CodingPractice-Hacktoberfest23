class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());

        int N = stones.size(), low = N;
        for (int i = 0, j = 0; j < N; ++j) {
            while (stones[j] - stones[i] + 1 > N) {
                ++i;
            }
            if (N - (j - i + 1) == 1 && N - (stones[j] - stones[i] + 1) == 1) {
                low = min(low, 2);
            } else {
                low = min(low, N - (j - i + 1));
            }
        }

        int high = 1 + max((stones[N - 1] - stones[1] + 1) - N,  // Move to right most
                           (stones[N - 2] - stones[0] + 1) - N); // Move to left most
        return {low, high};
    }
};



















