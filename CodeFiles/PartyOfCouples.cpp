#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def 	Using Xoring Concept.
 *
 * @details 	As the Xor of two same element is 0, it was expected that XORing all the elements will lead to the only odd one out number in the end.
 */
class Solution
{
public:
	int findSingle(int n, int arr[])
	{
		int Xor = 0;
		for (int i = 0; i < n; i++)
			Xor ^= arr[i];

		return Xor;
	}
};