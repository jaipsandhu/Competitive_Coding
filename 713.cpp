class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s = nums.size();
        int no = 0;

        for (int i = 0; i < s; i++) {
            int product = 1;
            for (int j = i; j < s; j++) {
                product *= nums[j];
                if (product < k) {
                    no++;
                } else {
                    break;
                }
            }
        }
        return no;
    }
};