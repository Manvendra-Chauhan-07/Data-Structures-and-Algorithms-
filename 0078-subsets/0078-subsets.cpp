class Solution {
public:

    vector<vector<int>> sub(int index, int n, vector<int> &arr, vector<vector<int>> &ans,vector<int> nums){

        if(index==n){
            ans.push_back(arr);
            return ans;
        }

        arr.push_back(nums[index]);
        sub(index+1,n,arr,ans,nums);
        arr.pop_back();
        sub(index+1,n,arr,ans,nums);

        return ans;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        //we do it by making a call to whether take the element or no taking the element.

        vector<vector<int>> ans;
        vector<int> arr;

        int n=nums.size();

        sub(0,n,arr,ans,nums);


        return ans;
    }
};