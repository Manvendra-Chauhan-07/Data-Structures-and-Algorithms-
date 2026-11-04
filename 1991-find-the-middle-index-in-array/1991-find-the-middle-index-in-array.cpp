class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n=nums.size();

        int prefix[n];
        prefix[0]=0;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }

        int suffix[n];
        suffix[n-1]=0;

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i+1];
        }


        int ans = -1;

        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]){
                ans=i;
                break;
            }
        }

        return ans;
    }
};