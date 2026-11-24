class Solution {
public:

    void findingSubset(int index, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans){

        if(index==n){
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[index]);
        findingSubset(index+1,n,nums,arr,ans);
        arr.pop_back();
        findingSubset(index+1,n,nums,arr,ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> arr;

        int n = nums.size();

        findingSubset(0,n,nums,arr,ans);

        return ans;
    }
};