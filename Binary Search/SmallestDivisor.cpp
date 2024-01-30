int calc(vector<int>arr,int divisor){
	int n = arr.size();
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += ceil((double)(arr[i])/(double)(divisor));
	}
	return sum;
}
int maxElement(vector<int>arr){
	int n = arr.size();
	int maxi = 0;
	for(int i=0;i<n;i++) maxi = max(maxi,arr[i]);
	return maxi;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int n = arr.size();
	if(n>limit) return -1;
	int low=1, high=maxElement(arr);
	while(low<=high){
		int mid = (low+high)/2;
		if(calc(arr,mid)<=limit) high = mid - 1;
		else low = mid+1;
	}
	return low;
}