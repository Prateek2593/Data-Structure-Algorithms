//Program to find two elements from array such that their sum = target
//using HashMap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num =  nums[i];
            int rem = target - num;
            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem],i};
            }
        mpp[num]=i;
        }
    return {-1,-1};
    }
};


//Program to find two elements from array such that their sum = target
//first sorted the array and return YES if there exists such two numbers
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(),book.end());
    int left=0,right=n-1;
    while(left<right){
        int sum = book[left] + book[right];
        if(sum==target){
            return "YES";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}
