// C++ program to print sum of all substring of
// a number represented as a string
#include <bits/stdc++.h>
using namespace std;
 
// Utility method to convert character digit to
// integer digit
int toDigit(char ch) { return (ch - '0'); }
 
// Returns sum of all substring of num
int sumOfSubstrings(string num)
{
    int n = num.length();
 
    // storing prev value
    int prev = toDigit(num[0]);
 
    int res = prev; // ans
 
    int current = 0;
 
    // substrings sum upto current index
    // loop over all digits of string
    for (int i = 1; i < n; i++) {
        int numi = toDigit(num[i]);
 
        // update each sumofdigit from previous value
        current = (i + 1) * numi + 10 * prev;
 
        // add current value to the result
        res += current;
        prev = current; // update previous
    }
 
    return res;
}
 
// Driver code
int main()
{
    string num = "1234";
   
      // Function call
    cout << sumOfSubstrings(num) << endl;
    return 0;
}
