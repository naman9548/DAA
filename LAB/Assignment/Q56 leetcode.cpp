class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int start = 0, totalgas = 0, totalcost = 0;
    for (int i = 0; i < gas.size(); i++) {
        totalgas= totalgas+ gas[i] - cost[i];
        totalcost=totalcost+gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if(total>=0)
        return start;
    else
        return -1;
    }
};
