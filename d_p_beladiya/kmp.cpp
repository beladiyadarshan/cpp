https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP



class Solution {
public:
    int strStr(string text, string pat) {
        int m = text.size(), n = pat.size();
        if (!n) {cout<<0;
            return 0;
        }
        vector<int> lps = kmpProcess(pat);
        for (int i = 0, j = 0; i < m;) {
            if (text[i] == pat[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && text[i] != pat[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1]; 
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};