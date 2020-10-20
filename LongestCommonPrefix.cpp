/* LeetCode: Longest Common Prefix
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/ */

/* Vertical Scanning Approach */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        int idx = 0;
        while (true) {
            for (auto& s : strs)
                if (idx >= s.size() || s[idx] != strs[0][idx])
                    return strs[0].substr(0,idx);
            idx++;
        }

        return "";
    }
};



/* Divide and Conquer Approach */
#define min(a,b) ((a) < (b) ? (a) : (b)) 

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    return longestCommonPrefix(strs, 0, strs.size()-1);
}
 
string longestCommonPrefix(const vector<string>& strs, int l, int r) {
    if (l == r) {
        return strs[l];
    } else {
        int mid = (l+r)/2;
        string lcpLeft = longestCommonPrefix(strs, l, mid);
        string lcpRight = longestCommonPrefix(strs, mid+1, r);
        return commonPrefix(lcpLeft, lcpRight);
    }
}
 
string commonPrefix(const string left, const string right) {
    int minLen = min(left.size(), right.size());
    for (int i = 0; i < minLen; ++i)
        if (left[i] != right[i])
            return left.substr(0,i);
    return left.substr(0,minLen);
}
/* In the worst case we have n equal strings with length m
 * Time complexity: O(S), where S is the number of all characters in the array, S=m⋅n Time complexity is 2⋅T(2/n)+O(m). Therefore time complexity is O(S). In the best case this algorithm performs O(minLen⋅n) comparisons, where minLen is the shortest string of the array
 * Space complexity: O(m⋅logn). There is a memory overhead since we store recursive calls in the execution stack. There are logn recursive calls, each store need m space to store the result, so space complexity is O(m⋅logn) */
 
 
 
/* Binary Search Approach */
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";
 
    int minLen = INT_MAX;
    for (string str : strs)
        minLen = min(minLen, str.size());
 
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low+high)/2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substr(0, (low+high)/2);
}
 
bool isCommonPrefix(const vector<string>& strs, int len) {
    string str = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); ++i)
        if (strs[i].rfind(str, 0) != 0)	// if strs[i] does not start with str
            return false;
    return true;
}
/* In the worst case we have n equal strings with length m
 * Time complexity: O(S⋅logm), where S is the sum of all characters in all strings. The algorithm makes logm iterations, for each of them there are S=m⋅n comparisons, which gives in total O(S⋅logm) time complexity.
 * Space complexity: O(1). We only used constant extra space. */
