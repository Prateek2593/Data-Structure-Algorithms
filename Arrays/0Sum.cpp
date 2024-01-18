#include<vector>
#include<map>
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	int n = arr.size();
	map<int,int>mpp;
	int sum=0;
	int maxLen = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum==0){
			maxLen = max(maxLen,i+1);
		}
		if(mpp.find(sum)!=mpp.end()){
			int len = i-mpp[sum];
			maxLen = max(maxLen,len);
		} 
		else{
			mpp[sum]=i;
		}
	}
	return maxLen;
}