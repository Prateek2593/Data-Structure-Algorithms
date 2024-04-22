/*
752. Open the Lock
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/


class Solution {
public:
    void fillNeighbours(queue<string>&que, string &curr, unordered_set<string> &dead){
        for(int i=0;i<4;i++){
            char ch = curr[i];

            char dec = ch=='0' ? '9' : ch-1;
            char inc = ch=='9' ? '0' : ch+1;

            curr[i] = dec;
            if(!dead.count(curr)){
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(!dead.count(curr)){
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));

        string start = "0000";
        if(dead.count(start)) return -1;

        int level = 0;
        queue<string> que;
        que.push(start);
        while(!que.empty()){
            int n = que.size();
            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == target) return level;

                fillNeighbours(que, curr, dead);
            }
            level++;
        }
        return -1;
    }
};
