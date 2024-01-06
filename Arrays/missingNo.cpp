//Program to find the missing number 
//Using the XOR method
//Time Complexity->O(N) and Space Complexity->O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int XOR1=0,XOR2=0;
        for(int i=0;i<n;i++){
            XOR2 = XOR2 ^ nums[i];
            XOR1 = XOR1 ^ (i+1);
        }
        //XOR1 = XOR1 ^ (n);
        return (XOR1^XOR2);
    }
    
};