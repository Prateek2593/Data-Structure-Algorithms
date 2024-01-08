//Program to calculate majority Element whose occurence is greater than (n/2)
int majorityElement(vector<int> v) {
	// Write your code here
	int n= v.size();
	int count=0;
	int element;
	for(int i=0;i<n;i++){
		if(count==0){
			count=1;
			element=v[i];
		}
		else if(v[i]==element) count++;
		else count--;
	}
	int count1=0;
	for(int i=0;i<n;i++){
		if(v[i]==element) count1++;
	}
	if(count1>n/2){
		return element;
	}
	return -1;
}