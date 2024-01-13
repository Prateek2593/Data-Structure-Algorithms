vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int left=0,top=0,right=m-1,bottom=n-1;
    vector<int>ans;
    //right->bottom>left->top

    while(top<=bottom && left<=right){
        //right-> left- right
        for(int i=left;i<=right;i++){
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        //bottom->top - bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(MATRIX[i][right]);
        }
        right--;
        
        if(top <= bottom){
            //left->right-left
            for(int i=right;i>=left;i--){
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        
        if(left<=right){
            //top->bottom-top
            for(int i=bottom;i>=top;i--){
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
        
    }
        
    return ans;
}