class Solution {
public:

    void Heapify(vector<int> &nums, int index, int n){

        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if(left<n && nums[left]>nums[largest]){
            largest=left;
        }
        if(right<n && nums[right]>nums[largest]){
            largest=right;
        }

        if(largest!=index){
            swap(nums[largest],nums[index]);
            Heapify(nums,largest,n);
            
        }
    }

    void buildMaxHeap(vector<int> &nums, int n){

        for(int i=n/2-1;i>=0;i--){
            Heapify(nums,i,n);
        }
    }

    void sortArray(vector<int> &nums, int n){

        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            Heapify(nums,0,i);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        

        buildMaxHeap(nums,nums.size());
        sortArray(nums,nums.size());


        return nums;
    }
};