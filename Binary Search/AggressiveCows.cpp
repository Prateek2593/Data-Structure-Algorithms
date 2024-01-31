#include<bits/stdc++.h>
bool canWePlace(vector<int>stalls,int dist,int cows){
    int n=stalls.size();
    int cntCows=1, last=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-last>=dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 0,high = stalls[n-1] - stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(stalls,mid,k)) low = mid+1;
        else high = mid - 1;
    }
    return high;
}