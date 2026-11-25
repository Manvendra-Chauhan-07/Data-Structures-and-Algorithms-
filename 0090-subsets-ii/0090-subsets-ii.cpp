class Solution {
public:

    void findSubset(int index, int n, set<vector<int>> &s, vector<int> &nums,vector<int> &arr, vector<vector<int>> &ans){

        if(index==n){
            if(s.find(arr)==s.end()){
                s.insert(arr);
                ans.push_back(arr);
            }
            return;
        }

        arr.push_back(nums[index]);
        findSubset(index+1,n,s,nums,arr,ans);

        arr.pop_back();
        findSubset(index+1,n,s,nums,arr,ans);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        set<vector<int>> s;

        vector<int> arr;
        vector<vector<int>> ans;

        int n = nums.size();

        findSubset(0,n,s,nums,arr,ans);

        return ans;
    }
};