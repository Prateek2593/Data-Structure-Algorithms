#include<iostream>
using namespace std;

//Program to print element at a specified row and columns number in a Pascal Triangle
int nCr(int n, int r){
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res *(n-i);
        res = res/(i+1);
    }
    return res;
}
int pascalTriangle(int row,int col){
    int element = nCr(row-1,col-1);
    return element;
}
int main(){
    int row,col;
    cin>>row>>col;
    
    int element= pascalTriangle(row,col);
    cout<<element;
    return 0;
}


//Program to print Nth row of Pascal Triangle
int main(){
    int n;
    cin>>n;
    
    long long ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans*(n-i);
        ans = ans/(i);
        cout<<ans<<" ";
    }
}


//Program to print entire Pascal Triangle for a specified row number
vector<int> generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans = ans*(row-col);
        ans = ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}