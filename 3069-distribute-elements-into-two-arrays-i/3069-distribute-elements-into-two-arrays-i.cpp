class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a1;
        vector<int> a2;
        int p1 = 0, p2 = 0;

        if (n <= 2)
            return nums;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        p1 = a1[0];
        p2 = a2[0];

        for (int i = 2; i < n; i++) {
            if (p1 > p2) {
                a1.push_back(nums[i]);
                p1 = nums[i];
            } else {
                a2.push_back(nums[i]);
                p2 = nums[i];
            }
        }
        a1.insert(a1.end() ,a2.begin() ,a2.end());
        return a1;
    }
};