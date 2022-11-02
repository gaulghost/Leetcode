class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> genearr{'A', 'C', 'G', 'T'};
        unordered_set<string> us{bank.begin(),bank.end()};
        queue<string> q;
        q.push(start);
        int level = -1;
        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int i =0; i<sz; i++){
                string tp = q.front();
                q.pop();
                if(tp == end) return level;
                us.erase(tp);
                for(int j =0; j<tp.size(); j++){
                    for(int k = 0; k<genearr.size(); k++){
                        string tempstr = tp;
                        tempstr[j] = genearr[k];
                        if(us.find(tempstr) != us.end()) q.push(tempstr);
                    }
                }
            }
        }
        return -1;
    }
};