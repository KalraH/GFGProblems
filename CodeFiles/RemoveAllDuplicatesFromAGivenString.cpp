#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-: T: O(N), S: O(N)
 *
 * @def		Using HashMap to identify duplicates.
 *
 * @details 	Traver through the whole string, use a HashMap keep track of characters visited & if a new character is found, add it to the soln string. 
 * 		This will make sure the order is maintained in soln as well as Find operation in HashMap will keep timecomplexity less. 
 */
class Solution
{
public:
	string removeDuplicates(string str)
	{
		unordered_map<char, int> aMap;
		string soln;
		for (auto i: str)
		{
			if (aMap.find(i) == aMap.end())
			{
				aMap[i]++;
				soln += i;
			}
		}
		return soln;
	}
};