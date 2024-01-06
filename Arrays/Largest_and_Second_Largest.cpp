#include <bits/stdc++.h> 
//Program to find the largest element in the array
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest=arr[0];
    for(int i=0;i,n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

//Program to find the second largest element in the array
int SecondLargest(int n, vector<int> a){
    int largest = INT_MIN;
    int sLargest = INT_MIN;

    for(int i=0;i<n;i++){
        if(a[i]>largest){
            sLargest=largest;
            largest=a[i];
        }
        else if (a[i]!=largest && a[i]>sLargest){
            sLargest=a[i];
        }
    }
    return sLargest;