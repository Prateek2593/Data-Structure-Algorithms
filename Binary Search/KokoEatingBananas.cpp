#include <bits/stdc++.h>
int maxElement(vector<int>v){
    int n = v.size();
    int maxElement = INT_MIN;
    for(int i=0;i<n;i++) maxElement = max(v[i],maxElement);
    return maxElement;
}
int totalHours(vector<int>v, int hours){
    int n = v.size();
    int totalHours = 0;
    for(int i=0;i<n;i++){
        totalHours += ceil((double)(v[i])/(double)(hours));
    }
    return totalHours;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    int n = v.size();
    int low = 1, high = maxElement(v);
    while(low<=high){
        int mid = (low+high)/2;
        int totalH = totalHours(v,mid);
        if(totalH<=h) high = mid - 1;
        else low = mid+1;
    }
    return low;
}