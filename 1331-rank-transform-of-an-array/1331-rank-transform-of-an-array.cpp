class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        for(int i=0;i<n;i++){
            q.push({arr[i],i});
        }

        int rank = 1;

        vector<int> ans(n);

        while(!q.empty()){

            auto p = q.top();

            int top = (p.first);
            q.pop();

            ans[p.second]=rank;

            if(p.first < q.top().first){
                rank++;
            }
        }

        return ans;

    }
};