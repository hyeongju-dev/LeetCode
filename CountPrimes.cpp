/* LeetCode: Count Primes
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/ */

#include <vector>
using namespace std;

/* Sieve of Eratosthenes Approach */
class Solution {
public:
    int countPrimes(int n) {
      int res = 0;
      vector<bool> isPrime(n, true);
      for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
          ++res;
          for (int j = i; j < n; j += i)
            isPrime[j] = false;
        }
      }

      return res;
    }
};
/* Time complextiy: O(n)
 * Space complexity: O(n) */
