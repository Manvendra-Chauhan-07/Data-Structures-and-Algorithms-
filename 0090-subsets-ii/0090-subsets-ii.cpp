class Solution {
public:

    void findSubset(int index, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans){

        ans.push_back(arr);

        for(int i = index;i<n;i++){

            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }

            arr.push_back(nums[i]);

            findSubset(i+1,n,nums,arr,ans);

            arr.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> arr;
        int n = nums.size();


        findSubset(0,n,nums,arr,ans);

        return ans;
    }
};