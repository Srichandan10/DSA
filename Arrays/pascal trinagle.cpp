class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,0);
            temp[0]=1;
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            temp[i]=1;
            ans[i]=temp;
        }
        return ans;
    }
};