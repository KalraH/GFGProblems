#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def 	Simple Brute Force.
 *
 * @details 	Just traverse the array till (N-2)th element, & at runtime keep swapping the elements of array.
 */
class Solution
{
public:
	void swapElements(int arr[], int n)
	{
		for (int i = 0; i < (n - 2); i++)
		{
			int temp = arr[i + 2];
			arr[i + 2] = arr[i];
			arr[i] = temp;
		}
	}
};