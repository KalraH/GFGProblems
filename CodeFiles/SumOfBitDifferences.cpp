#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2), S: O(1)
 *
 * @def		Simple Brute Force.
 *
 * @details	We run a nested loop & find the XOR of all possible pairs in the array. Then we add up the bit diffs of all the pairs & return the sum.
 * 		The XORing of both number leads to a value whose no. of HIGH bits provide the diff of bits in the both numbers.
 * 		E.g.: { 6 (0110) ^ 10 (1010) = 12 (1100) } No. of high bits in 12 are 2 which is the bit diff of 6 & 10.
 */
class Solution
{
public:
	long long sumBitDifferences(int arr[], int n)
	{
		long long soln = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// Calculating the XOR of both numbers.
				long temp = (arr[i] ^ arr[j]);

				// The below fn is used to count the no. of 1's in the binary representation of the input number.
				soln += __builtin_popcount(temp);
			}
		}
		return soln;
	}
};