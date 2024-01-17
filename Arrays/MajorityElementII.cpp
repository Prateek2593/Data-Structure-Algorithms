vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int n= v.size();
	int count1=0,count2=0;
	int el1=INT_MIN, el2=INT_MIN;

	for(int i=0;i<n;i++){
		if(count1==0 && el2!=v[i]){
			el1=v[i];
			count1++;
		}
		else if(count2==0 && el1!=v[i]){
			el2=v[i];
			count2++;
		}
		else if(v[i]==el1) count1++;
		else if(v[i]==el2) count2++;
		else{
			count1--;
			count2--;
		}
	}

	vector<int>ls;
	count1=0,count2=0;
	for(int i=0;i<n;i++){
		if(v[i]==el1) count1++;
		if(v[i]==el2) count2++;
	}

	int mini= int(n/3)+1;
	if (count1 >= mini) ls.push_back(el1);
    if (count2 >= mini) ls.push_back(el2);

	sort(ls.begin(),ls.end());

	return ls;
}