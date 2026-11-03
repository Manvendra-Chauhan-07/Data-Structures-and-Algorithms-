class Solution {
public:

    int ans;
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        

        int rows = matrix.size();
        int columns = matrix[0].size();


        priority_queue<int, vector<int>, greater<int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                q.push(matrix[i][j]);
            }
        }

        

        while(!q.empty() && k--){
            ans = q.top();
            q.pop();
        }

        return ans;
    }
};