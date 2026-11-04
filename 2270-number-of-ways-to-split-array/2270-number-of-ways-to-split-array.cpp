class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long n=nums.size();

        long long  startSum[n];
        startSum[0] = nums[0];

        for(long long i=1;i<n;i++){
            startSum[i]=startSum[i-1]+nums[i];
        }

        long long endSum[n];
        endSum[n-1] = nums[n-1];

        for(long long i=n-2;i>=0;i--){
            endSum[i]=endSum[i+1]+nums[i];
        }

        long long count = 0;

        for(long long i=0;i<n-1;i++){
            if(startSum[i]>=endSum[i+1]){
                count++;
            }
        }

        return count;
    }
};