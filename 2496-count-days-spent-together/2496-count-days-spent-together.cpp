class Solution {
public:
    int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int convert(string &s) {
        string m, d;
        m += s[0];
        m += s[1];

        d += s[3];
        d += s[4];

        int count = 0; 
        int mm = stoi(m);
        int dd = stoi(d);

    
        for (int i = 0; i < mm; i++) {
            count += mon[i];
        }
        count += dd;

        return count;
    }

    int countDaysTogether(string aA, string lA, string aB, string lB) {
        int a = convert(aA);
        int b = convert(aB);
        int c = convert(lA);
        int d = convert(lB);
        int arrival = max(a, b);
        int depart = min(c, d);
        if (depart < arrival) {
            return 0; // No overlap
        }
        return depart - arrival + 1; // Include the departure day
    }
};