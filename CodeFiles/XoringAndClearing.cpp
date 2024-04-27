#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def
 *
 * @details
 */
class Solution
{
public:
	void printArr(int n, int arr[])
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	void setToZero(int n, int arr[])
	{
		for (int i = 0; i < n; i++)
			arr[i] = 0;
	}

	void xor1ToN(int n, int arr[])
	{
		for (int i = 0; i < n; i++)
			arr[i] ^= i;
	}
};