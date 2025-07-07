#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());

        // Min-heap to store end days of available events
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = events.size();
        int day = 1;       // Current day
        int i = 0;         // Index to iterate events
        int res = 0;       // Count of events attended

        // Find the maximum end day
        int lastDay = 0;
        for (auto& e : events)
            lastDay = max(lastDay, e[1]);

        // Iterate from day 1 to last possible day
        while (day <= lastDay) {
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Remove events that have already expired
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();

            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};
