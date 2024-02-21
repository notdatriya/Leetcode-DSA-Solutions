class Solution {
public:
    string minWindow(string s, string t) {
        
if (s.empty() || t.empty()) {
            return "";
        }        
        int i=0;
        
        unordered_map<char,int>smap;
        unordered_map<char,int>tmap;
        
        int left = 0;
        int right = 0;
       

        int anslength = INT_MAX;

        for (char c : t) {
            tmap[c]++;
        }
        
         int have = 0;
        int need = tmap.size();
        for (int j = 0; j < s.length(); j++) {
            char c = s[j];
            smap[c]++;

            if (tmap.find(c) != tmap.end() && smap[c] == tmap[c]) {
                have++;
            }

            while (have == need) {
                if (j - i + 1 < anslength) {
                    anslength = j - i + 1;
                    left = i;
                    right = j;
                }

                smap[s[i]]--;
                if (tmap.find(s[i]) != tmap.end() && smap[s[i]] < tmap[s[i]]) {
                    have--;
                }
                i++;
            }
        }

        if (anslength == INT_MAX) return "";
        else {
            return s.substr(left, anslength);
        }
    }
};