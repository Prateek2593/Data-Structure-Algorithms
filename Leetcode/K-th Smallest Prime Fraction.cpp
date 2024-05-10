/*786. K-th Smallest Prime Fraction
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

Example 1:
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.*/

/*Approach 1 using brute force*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, pair<int, int>>> fractions; // Store fraction value and corresponding indices
        
        // Generate all possible fractions
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double frac_value = double(arr[i]) / arr[j]; // Calculate the fraction value
                fractions.push_back({frac_value, {i, j}});
            }
        }
        
        // Sort fractions based on their values
        sort(fractions.begin(), fractions.end());
        
        // Return kth smallest fraction as a pair of integers
        return {arr[fractions[k - 1].second.first], arr[fractions[k - 1].second.second]};
    }
};

/*Approach 2 using max heap*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>>pq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double fraction = (double)arr[i]/arr[j];
                pq.push(vector<double>{fraction, (double)arr[i], (double)arr[j]});
                if(pq.size()>k) pq.pop();
            }
        }
        auto vec = pq.top();
        vector<int>result(2);
        result[0] = vec[1];
        result[1] = vec[2];

        return result;
    }
};

/*Approach 3 using min heap*/
class Solution {
public:
    typedef vector<double> V;
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push({1.0*arr[i]/arr.back(), (double)(i), (double)(n-1)});
        
        int smallest = 1;
        
        while(smallest < k) {
            V vec = pq.top();
            pq.pop();
            
            int i = vec[1];
            int j = vec[2]-1;

            
            pq.push({1.0*arr[i]/arr[j], (double)(i), (double)(j)});
            smallest++;
        }
        
        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
};
