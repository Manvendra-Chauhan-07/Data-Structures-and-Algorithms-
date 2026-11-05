class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n=nums.size();

        int count = 0;

        int minimum = INT_MAX;

        for(int i=0;i<n;i++){
            minimum = min(minimum,nums[i]);
        }

        for(int i=0;i<n;i++){

            count = count + (nums[i]-minimum);
        }

        return count;
        
    }
};