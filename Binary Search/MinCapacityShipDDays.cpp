int calcDays(vector<int>arr,int capacity){
    int n =  arr.size();
    int load=0,days=1;
    for(int i=0;i<n;i++){
        if(load+arr[i]>capacity){
            days++;
            load = arr[i];
        }
        else load += arr[i];
    }
    return days;
}
int maxElement(vector<int>arr){
    int n = arr.size();
    int maxi=0;
    for(int i=0;i<n;i++) maxi = max(maxi,arr[i]);
    return maxi;
}
int sum(vector<int>arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++) sum+=arr[i];
    return sum;
}
int leastWeightCapacity(vector<int> &arr, int d)
{
    int n = arr.size();
    int low = maxElement(arr), high = sum(arr);
    while(low<=high){
        int mid = (low+high)/2;
        int days = calcDays(arr,mid);
        if(days<=d) high = mid -1;
        else low = mid +1;
    }
    return low;
}