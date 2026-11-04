class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long long n = nums.size();

        long long startSum[n];
        startSum[0]=nums[0];

        for(long long i=1;i<n;i++){
            startSum[i]=startSum[i-1]+nums[i];
        }

        long long endSum[n];
        endSum[n-1]=nums[n-1];

        for(long long i=n-2;i>=0;i--){
            endSum[i]=endSum[i+1]+nums[i];
        }

        long long answerAverage = INT_MAX;
        long long answer = -1;

        for(long i=0;i<n;i++){
            long long startAverage = (startSum[i]/(i+1));

            long long endAverage = 0;

            if(i!=n-1){
                endAverage = (endSum[i+1]/(n-(i+1)));
            }

            long long calculate = abs(startAverage-endAverage);

            if(calculate<answerAverage){
                answerAverage=calculate;
                answer = i;
            }
        }

        return answer;
    }
};