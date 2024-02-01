#include<bits/stdc++.h>
int count(vector<int>arr,int pages){
    int n = arr.size();
    int students=1, pagesStu=0;
    for(int i=0;i<n;i++){
        if(pagesStu+arr[i]<=pages) pagesStu+=arr[i];
        else{
            students++;
            pagesStu=arr[i];
        }
    }
    return students;
}
int findPages(vector<int>& arr, int n, int m) {
    //students are greater than books
    if(m>n) return -1;
    //low is set as the maximum element of the array
    int low = *max_element(arr.begin(),arr.end());
    //high is set as the sum of entire array
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int students = count(arr,mid);
        if(students>m) low = mid+1;
        else high=mid-1;
    }
    return low;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    return findPages(a,a.size(),k);
}