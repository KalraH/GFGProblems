#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2), S: O(N)
 *
 * @def 	BruteForce.
 *
 * @details 	Simply traverse the List & whenever we encounter 0 at queries[i][0], we add queries[i][1] into the soln list. Whenever we ecounter 1 at queries[i][0],
 * 		we XoR the entire soln list with queries[i][1].
 */
class Solution
{
public:
	vector<int> constructList(int q, vector<vector<int>> &queries)
	{
		vector<int> soln;
		soln.push_back(0);

		for (int i = 0; i < q; i++)
		{
			if (queries[i][0] == 0)
				soln.push_back(queries[i][1]);
			else
			{
				for (int j = 0; j < soln.size(); j++)
					soln[j] ^= queries[i][1];
			}
		}
		sort(soln.begin(), soln.end());

		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N), S: O(N)
 *
 * @def		Reducing the time for XORing the entire Soln list.
 *
 * @details 	Simply traverse the List, we maintain a variable tempXor with Values XORed which have value 1 in the queries[i][0]. while traversing, whenever we 
 * 		encounter 0 at queries[i][0], we add (queries[i][1] XOR tempXor) into the soln list or Whenever we ecounter 1 at queries[i][0], we XoR the value with 
 * 		tempXor variable. At end, we traverse the entire soln list once while XORing it with the tempXor variable.
 */
class Solution
{
public:
	vector<int> constructList(int q, vector<vector<int>> &queries)
	{
		int tempXor = 0;
		vector<int> soln;
		soln.push_back(0);

		for (int i = 0; i < q; i++)
		{
			if (queries[i][0] == 0)
				soln.push_back(queries[i][1] ^ tempXor);
			else
				tempXor ^= queries[i][1];
		}

		for (auto &i : soln)
			i ^= tempXor;

		sort(soln.begin(), soln.end());

		return soln;
	}
};