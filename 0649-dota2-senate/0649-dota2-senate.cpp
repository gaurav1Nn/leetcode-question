class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r;
        queue<int> d;
        queue<int> q;
        for(int i=0;i<s.size();i++){
            q.push(i);
            if(s[i]=='R')r.push(i);
            else d.push(i);
        }
        while(q.size()>0){
            if(s[q.front()]=='X') q.pop();
            else if(s[q.front()]=='R'){
                // check for victory
                if(d.size()==0) return "Radiant";
                else{//take rights of next d
                    s[d.front()]='X';
                    d.pop();
                    // work done;
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else{
                // check for victory
                if(r.size()==0) return "Dire";
                else{//take rights of next d
                    s[r.front()]='X';
                    r.pop();
                    // work done;
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
            
        }
        if(s[q.front()]=='R') return  "Radiant";
        else return "Dire";
    }
};