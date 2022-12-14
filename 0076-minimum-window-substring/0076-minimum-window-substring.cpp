class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }
        int start = 0, end = 0, minStart = 0, minLen = INT_MAX, counter = t.length();
        while (end < s.length()) {
              char c1 = s[end];
              if (map[c1] > 0) counter--;
              map[c1]--;
              end++;
              while (counter == 0) {
                    if (minLen > end - start) {
                          minLen = end - start;
                          minStart = start;
                    }
                    char c2 = s[start];
                    map[c2]++;
                    if (map[c2] > 0) counter++;
                    start++;
              }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};