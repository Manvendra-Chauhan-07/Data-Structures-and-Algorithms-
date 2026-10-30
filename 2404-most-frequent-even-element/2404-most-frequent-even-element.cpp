class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mpp[nums[i]]++;
            }
        }

        int ans = -1;
        int max = -1;

        for(auto &it : mpp){

            if(it.second>max){
                max=it.second;
                ans=it.first;
            }
            if(max==it.second && it.first<ans){
                ans=it.first;
                max=it.second;
            }
        }

        return ans;

    }
};