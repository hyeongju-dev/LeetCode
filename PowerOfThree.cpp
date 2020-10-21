/* LeetCode: Power of Three
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/745/ */

#include <cmath>

/* Mathematics Approach */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }
};
/* Time complextiy: Unknown. The expensive operation here is log, which upper bounds the time complexity of our algorithm. The implementation is dependent on the language we are using and the compiler
 * Space complexity: O(1). We are not using any additional memory. The epsilon variable can be inlined. */
