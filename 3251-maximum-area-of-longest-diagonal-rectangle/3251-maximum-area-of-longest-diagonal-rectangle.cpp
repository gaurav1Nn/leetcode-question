class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestD2 = -1;  // largest squared diagonal seen
        long long bestArea = 0; // area for that best diagonal

        for (const auto& r : dimensions) {
            long long L = r[0], W = r[1];
            long long d2 = L*L + W*W; // squared diagonal
            long long area = L * W;

            if (d2 > bestD2 || (d2 == bestD2 && area > bestArea)) {
                bestD2 = d2;
                bestArea = area;
            }
        }
        return static_cast<int>(bestArea);
    }
};
