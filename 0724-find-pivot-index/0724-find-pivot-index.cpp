class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        int totalSum = 0;

        for(int i=0;i<n;i++){
            totalSum = totalSum + nums[i];
        }

        int prefix[n];
        prefix[0]=0;

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }

        for(int i=0;i<n;i++){

            int ans = totalSum-nums[i]-prefix[i];
            if(ans==prefix[i]){
                return i;
            }
        }

        return -1;
    }
};