/* Gas Station

	There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

	Note:
	The solution is guaranteed to be unique.
	
	Try to loop the circle station by station, made the next station as a new start station when you face a gap. Return true if you reach the start station with gas remain, return false if you reach the first gap again.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = gas.size();
        if(size == 0) return -1;
		// return to itself
        if(size == 1) return -(gas[0] < cost[0]);
        int current_gas = 0, start = 0, first_start = 0, i = 0;
        while(1) {
            int next = (i + 1) % size;
            current_gas += (gas[i] - cost[i]);
            if(current_gas < 0) {
                if(first_start != 0 && next == first_start) return -1;
                if(first_start == 0) first_start = next;
                start = next;
                current_gas = 0;
            }
            else if(next == start) return start;
            i = next;
        }
    }
};