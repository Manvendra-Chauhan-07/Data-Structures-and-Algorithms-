class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int count = 0;

        int n=nums.size();

        int maximum = INT_MIN;

        for(int i=0;i<n;i++){
            maximum = max(maximum,nums[i]);
        }

        for(int i=0;i<n;i++){
            count = count + abs(nums[i]-maximum);
        }

        return count;
    }
};