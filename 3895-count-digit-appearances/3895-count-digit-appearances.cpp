class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int count=0;

        for(int i=0;i<nums.size();i++){

            int num = nums[i];
            int digitCount = 0;
            while(num>0){
                int rem = num%10;
                if(rem==digit){
                    digitCount++;
                }
                num=num/10;
            }

            count=count+digitCount;
        }

        return count;
    }
};