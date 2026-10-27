class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> q;

        for(int i=0;i<piles.size();i++){
            q.push(piles[i]);
        }

        while(!q.empty() && k){
            
            int value = q.top();
            q.pop();

            q.push(value - (floor((value)/2)));

            k--;
        }

        

        int ans = 0;

        while(!q.empty()){
            cout<<q.top();
            ans=ans+q.top();
            q.pop();
        }

        return ans;
    }
};