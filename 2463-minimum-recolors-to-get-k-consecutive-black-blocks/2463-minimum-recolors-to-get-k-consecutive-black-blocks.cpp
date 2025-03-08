class Solution {
public:
    int minimumRecolors(string block, int k) {
        int n = block.size();
        queue<char> q;
        int white = 0;
        int min_count = INT_MIN;
        for(int i=0;i<k;i++){
            q.push(block[i]);
            if(block[i]=='W') white++;
        }
        min_count = white;
        for(int i=k;i<n;i++){
            if(q.front()=='W') white--;
            q.pop();
            q.push(block[i]);
            if(block[i]=='W') white++;
            min_count = min(white,min_count);
        }
        return min_count;

    }
};