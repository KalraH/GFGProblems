#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def		Using mathematical reasoning. For any number to-be divisible by 8, it's last 3 digits should be divisible by 3.
 *
 * @details	If the string size is less than 3, then just convert it into int using stoi() STL & find it's remainder with 8. If the number is greater than 8, 
 */
class Solution
{
public:
	int DivisibleByEight(string s)
	{
		int len = s.size();
		if (len <= 3)
			return (stoi(s) % 8) ? -1 : 1;

		return (stoi(s.substr(len - 3)) % 8) ? -1 : 1;
	}
};