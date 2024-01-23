int binarySearch(vector<int> &nums,int low,int high, int target){
    if(low>high) return -1;

    int mid = (low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target) return binarySearch(nums,low,mid-1,target);
    else return binarySearch(nums,mid+1,high,target);
}
int search(vector<int> &nums, int target) {
    int n = nums.size();
    //using iterative method
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
    
    //Using recursion
    return binarySearch(nums,0,nums.size()-1,target);
}