
/*

PROBLEM STATEMENT : 
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

//Naive Approach :
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        map<int, int> myMap;
        vector<int> result;
        set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (myMap[nums[i]] == 2)
            {
                s.insert(nums[i]);
            }
        }

        for (auto itr = s.begin(); itr != s.end(); ++itr)
        {
            result.push_back(*itr);
        }

        return result;
    }
};