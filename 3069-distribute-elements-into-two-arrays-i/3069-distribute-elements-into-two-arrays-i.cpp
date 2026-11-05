class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> arr1;

        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2;i<n;i++){
            
            int arr1Last = arr1[arr1.size()-1];
            int arr2Last = arr2[arr2.size()-1];

            if(arr1Last>arr2Last){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;

    }
};