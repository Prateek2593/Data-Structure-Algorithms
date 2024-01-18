#include <map>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    int xr = 0;
    map<int,int>mpp;
    mpp[xr]++;
    int count = 0;
    for(int i=0;i<n;i++){
        xr = xr^a[i];
        int x = xr ^ b;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}