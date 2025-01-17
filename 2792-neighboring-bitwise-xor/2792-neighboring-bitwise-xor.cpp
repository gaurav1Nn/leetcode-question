class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (auto element : derived) {
            XOR = XOR ^ element;
        }
        return XOR == 0;
    }
};