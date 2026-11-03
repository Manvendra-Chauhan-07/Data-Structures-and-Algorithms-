class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int n=nums.size();

        map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){

            if(mpp[a]==mpp[b]){
                return a>b;
            }
            return mpp[a]<mpp[b];
        });

        return nums;
    }
};