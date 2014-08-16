class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret(numRows,vector<int>());
        for(int i=0;i<numRows;++i) ret[i].resize(i+1);
        
        for(int i=0;i<numRows;++i)
        {
            for(int j=0;j<i+1;++j)
            {
                if(i == 0 || j == 0 || j == i) ret[i][j] = 1;
                else
                    ret[i][j] = ret[i-1][j]+ret[i-1][j-1];
            }
        }
        return ret;
    }
};
