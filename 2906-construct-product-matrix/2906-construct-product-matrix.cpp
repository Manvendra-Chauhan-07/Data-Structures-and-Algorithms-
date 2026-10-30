class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        vector<long> arr;
        
        long long rows = grid.size();
        long long columns = grid[0].size();


        for(long long i=0;i<rows;i++){
            for(long long j=0;j<columns;j++){
                arr.push_back(grid[i][j]);
            }
        }

        long long n = arr.size();
        long long prefix[n];
        prefix[0]=1;

        for(long long i=1;i<n;i++){
            prefix[i] = (prefix[i-1] * arr[i-1]) % 12345;
        }

        long long suffix[n];
        suffix[n-1]=1;

        for(long long i=n-2;i>=0;i--){
            suffix[i] = (suffix[i+1] * arr[i+1]) % 12345;
        }

        for(long long i=0;i<n;i++){
            arr[i] = prefix[i]*suffix[i];
        }

        long long k=0;

        for(long long i=0;i<rows;i++){
            for(long long j=0;j<columns;j++){
                grid[i][j]=((arr[k])%12345);
                k++;
            }
        }

        return grid;
    }
};