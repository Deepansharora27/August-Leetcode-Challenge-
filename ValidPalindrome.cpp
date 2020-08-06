/*

PROBLEM STATEMENT : 

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.


*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        //Solving Using the Two Pointer Approach:
        int i = 0;
        int j = s.length() - 1;

        if (s.empty())
        {
            return true;
        }

        bool isPalin = false;
        while (i <= j)
        {

            while (i < j && !isalnum(s[i]))
            {
                i++; //We are Ignoring if it is not a Alphanumeric Character
            }

            while (i < j && !isalnum(s[j]))
            {
                j--; //Ignoring if it is not a Alphanumeric Character
            }

            if (tolower(s[i]) == tolower(s[j]))
            {
                isPalin = true;
                i++; //Incrementing the First Pointer
                j--; //Decrementing the Second Pointer
            }
            else
            {
                isPalin = false; //Resetting the Flag Again
                break;
            }
        }

        return isPalin; //Returning the Boolean Variable at the End
    }
};