class Solution {
public:
    int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        // Store the input moveTime in a variable named roomMoveTime
        std::vector<std::vector<int>> roomMoveTime = moveTime;  
        int totalRows = roomMoveTime.size();
        int totalCols = roomMoveTime[0].size();
        
        // Priority queue to store (current_time, row, col, step_cost)
        using State = std::tuple<int, int, int, int>; // (current_time, row, col, step_cost)
        std::priority_queue<State, std::vector<State>, std::greater<State>> priorityQueue;
        priorityQueue.emplace(0, 0, 0, 1);  // Start at (0, 0) with time 0 and step cost 1
        
        std::vector<std::vector<int>> minimumArrivalTime(totalRows, std::vector<int>(totalCols, INT_MAX));
        minimumArrivalTime[0][0] = 0;

        // Directions for adjacent rooms (down, up, right, left)
        std::vector<std::pair<int, int>> adjacentDirections = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!priorityQueue.empty()) {
            auto [currentTime, currentRow, currentCol, currentStepCost] = priorityQueue.top();
            priorityQueue.pop();

            // If we reached the target room (totalRows - 1, totalCols - 1)
            if (currentRow == totalRows - 1 && currentCol == totalCols - 1) {
                return currentTime;
            }

            // Explore adjacent rooms
            for (const auto& [dx, dy] : adjacentDirections) {
                int nextRow = currentRow + dx;
                int nextCol = currentCol + dy;

                if (nextRow >= 0 && nextRow < totalRows && nextCol >= 0 && nextCol < totalCols) {
                    int waitTime = std::max(roomMoveTime[nextRow][nextCol] - currentTime, 0);
                    int newArrivalTime = currentTime + currentStepCost + waitTime;

                    // Only push to the queue if we found a better arrival time
                    if (newArrivalTime < minimumArrivalTime[nextRow][nextCol]) {
                        minimumArrivalTime[nextRow][nextCol] = newArrivalTime;
                        int nextStepCost = (currentStepCost == 2) ? 1 : 2;
                        priorityQueue.emplace(newArrivalTime, nextRow, nextCol, nextStepCost);
                    }
                }
            }
        }

        return -1; // Return -1 if the target room is unreachable
    }
};