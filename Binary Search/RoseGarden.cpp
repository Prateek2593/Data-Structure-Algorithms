int minElement(vector<int>arr){	
	int n = arr.size();
	int mini;
	for(int i=0;i<n;i++) mini = min(arr[i],mini);
	return mini;
}
int maxElement(vector<int>arr){
	int n = arr.size();
	int maxi;
	for(int i=0;i<n;i++) maxi = max(arr[i],maxi);
	return maxi;
}
bool possible(vector<int>arr, int day, int k, int m){
	int n = arr.size();
	int count=0, bouquets=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=day) count++;
		else{
			bouquets += (count/k);
			count = 0;
		}
	}
	bouquets += (count/k);
	return bouquets>=m;
}
int roseGarden(vector<int> arr, int k, int m){
	int n = arr.size();
	long long val = m * 1ll * k * 1ll;
	if(val>n) return -1;
	int low=minElement(arr), high=maxElement(arr);
	while(low<=high){
		int mid=(low+high)/2;
		if(possible(arr,mid,k,m)){
			high = mid - 1;
		}
		else low = mid+1;
	}	
	return low;
}