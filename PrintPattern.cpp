#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Approach-1: T: O(N), S: O(N)
 *
 * @def Simple Brute Force.
 *
 * @details Just decrease value of N by 5 untill its +ve & keep adding it to Result array. Once the value is -ve, just repeat same 
 * steps but this time by adding 5 to the value untill its not greater than N.
 */
class Solution
{
public:
	vector<int> pattern(int N)
	{
		vector<int> result;
		int temp = N;

		// Subtracting 5 to the value untill its not -ve.
		while (temp > 0)
		{
			result.push_back(temp);
			temp -= 5;
		}

		// Adding 5 to the value untill its not greater than N.
		while (temp <= N)
		{
			result.push_back(temp);
			temp += 5;
		}

		return result;
	}
};

/**
 * @brief Approach-2: T: O(N), S: O(N)
 *
 * @def Optimized using Reccursion. 
 *
 * @details Just take a flag (to identify if we have crossed 0 once or not), take a varible (to store original value), take a vector 
 * pointer (to store soln), and call the custom function recursively with the possible 4 conditions: 
 * 	--> If we haven't crossed/reached 0 once, keep reducing N by 5 & add it into result array.
 * 	--> Once we reach 0, add the value of N & start increasing N by 5.
 * 	--> Perform the addition untill we regain N as the original value.
 * 	--> Once N is equal to original value, return the result array.
 * Do take into consideration the condition if initially, N is 0 or -ve, just return value of N in a result. No need to do any 
 * further operation.
 */
class Solution
{
private:
	void findPattern(int N, bool *flag, vector<int> *result, int originalVal)
	{
		// If we have't crossed/reached 0 yet, we reduce 5 from N. 
		if ((N > 0) && !*flag)
		{
			result->push_back(N);
			findPattern(N - 5, flag, result, originalVal);
		}
		// Once we reach 0, now we need to add 5 to N.
		else if ((N <= 0) && !*flag)
		{
			*flag = true;
			result->push_back(N);
			findPattern(N + 5, flag, result, originalVal);
		}
		// We continue to add 5 to N untill we reach original value.
		else if (N != originalVal)
		{
			result->push_back(N);
			findPattern(N + 5, flag, result, originalVal);
		}
		// After reaching original value, return the result array consisting solution.
		else if (N == originalVal)
		{
			result->push_back(N);
			return;
		}
		return;
	}

public:
	vector<int> pattern(int N)
	{
		bool flag = false;
		vector<int> result;

		// Taking into consideration if N is 0 or -ve.
		if (N <= 0)
		{
			result.push_back(N);
			return result;
		}

		// Performing recursive calls to fill result array. Avoiding using any loop as mentioned in Question.
		findPattern(N, &flag, &result, N);

		return result;
	}
};