int ceil(vector<int> &arr, int n, int x){
	//smallest no in array >= x(lower bound)
	int low = 0, high = n-1;
  	int ans = n;
  	while(low<=high){
    	int mid = (low+high)/2;
    	if(arr[mid]>=x){
      		ans = arr[mid];
      		high = mid - 1;
    	}
    	else low = mid + 1;
  	}
	return ans;
}
int floor(vector<int> &arr, int n, int x){
	//largest no in array<=x
	int low = 0, high=n-1;
	int ans=-1;
	while(low<=high){
		int mid= (low+high)/2;
		if(arr[mid]<=x){
			ans = arr[mid];
			low = mid+1;
		}
		else high = mid - 1;
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int floor_value = floor(arr, n, x);
	int ceil_value = ceil(arr, n, x);
	return make_pair(floor_value,ceil_value);
}