class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s;

        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }

        vector<int> arr;

        set<int> st;

        for(int i=0;i<nums2.size();i++){
            if (s.find(nums2[i]) != s.end()) {
                st.insert(nums2[i]);
            }
        }

        for(auto it : st){
            arr.push_back(it);
        }

        return arr;
    }
};