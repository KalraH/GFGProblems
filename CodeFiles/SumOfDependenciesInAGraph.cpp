#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(V), S: O(1)
 *
 * @def 	Simple Brute Force.
 *
 * @details 	Just loop through Adjacency list & find for each Vertex, how many directed edges are possible & just sum them up.  
 */
class Solution
{
public:
	int sumOfDependencies(vector<int> adj[], int V)
	{
		int32_t soln = 0;

		// Calculating the no. of Dependencies for every single edge.
		for (int i = 0; i < V; i++)
			soln += adj[i].size();

		return soln;
	}
};