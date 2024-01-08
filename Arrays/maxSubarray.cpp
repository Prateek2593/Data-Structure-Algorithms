//Kadane’s Algorithm : Maximum Subarray Sum in an Array
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum=0, maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum +=arr[i];
        
        if(sum>maxi) maxi=sum;
        
        if(sum<0) sum=0;// If sum < 0: discard the sum calculated
        
        // To consider the sum of the empty 
        // uncomment the following check:
        if(maxi<0) maxi=0;
    }
    return maxi;
}