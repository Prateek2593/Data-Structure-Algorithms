//rotating an array by 90 degree
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        //Taking transpose of the matrix
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reversing every row of matrix
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};