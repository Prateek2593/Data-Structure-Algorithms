class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(),a.end());
    int n = a.size();
    int longest = 1;
    int counter = 0;
    int lastSmaller = INT_MIN;
    if(n==0) return 0;

    for(int i=0;i<n;i++){
        if(a[i]-1 == lastSmaller){
            counter++;
            lastSmaller=a[i];
        }
        else if (a[i]!=lastSmaller){
            counter=1;
            lastSmaller=a[i];
        }
        longest= max(longest,counter);
    }
    return longest;
    }
};