class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();

        int prefix[n];
        prefix[0]=1;
        int suffix[n];
        suffix[n-1]=1;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
            cout<<prefix[i];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
            cout<<suffix[i];
        }

        for(int i=0;i<n;i++){
            nums[i]=prefix[i]*suffix[i];
        }


        return nums;
    }
};