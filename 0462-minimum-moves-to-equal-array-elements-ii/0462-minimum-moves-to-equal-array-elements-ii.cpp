class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int start=0, end=nums.size()-1;
        int middle = nums[(end+(start-end)/2)];
        int count = 0;

        for(int i=0;i<nums.size();i++){
            count = count + abs(nums[i]-middle);
        }

        return count;
    }
};