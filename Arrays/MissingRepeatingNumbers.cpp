vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    /*
    S - Sn--> S is the sum of numbers present in array,
    Sn is the sum of first n natural numbers
    S2 - S2n--> S2 is the sum of squares of numbers in array 
    S2n is the sum of squares of first n natural numbers
    */
    long long S=0,S2=0;
    long long Sn = (n*(n+1))/2;
    long long S2n =(n * (n + 1) * (2 * n + 1)) / 6;
    for(int i=0;i<n;i++){
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    val2 = val2/val1;
    long long x = (val1+val2)/2;
    long long y = x-val1;
    return {(int)x,(int)y};
}