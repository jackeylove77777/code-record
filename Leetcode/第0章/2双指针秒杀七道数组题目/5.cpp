class Solution {
public:
	string longestPalindrome(string s) {
		string res = "";
		for (int i = 0; i < s.size(); i++) {
			string s1 = longestSubString(s, i, i);
			string s2 = longestSubString(s, i, i+1);
			res = res.size() < s1.size() ? s1 : res;
			res = res.size() < s2.size() ? s2 : res;
		}
        return res;
	}
	string longestSubString(string s, int l, int r) {
		while (l >= 0 && r < s.size() && s.at(l) == s.at(r)) l--, r++;
		return s.substr(l + 1, r - l -1);
	}
};