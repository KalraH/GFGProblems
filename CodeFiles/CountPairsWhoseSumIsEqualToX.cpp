#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N1 + N2), S: O(N1)
 *
 * @def		Iterating both LLs & checking for all possible pairs.
 *
 * @details	Iterate through 1st LL & save all its elements in a Map. We iterate through 2nd LL & find all possible pairs (x - element of LL2) in map.
 */
struct Node
{
	int data;
	struct Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

class Solution
{
public:
	int countPairs(struct Node *head1, struct Node *head2, int x)
	{
		int soln = 0;
		Node *tH = head1;
		unordered_map<int, int> aMap;
		
		while (tH)
		{
			aMap[tH->data]++;
			tH = tH->next;
		}

		tH = head2;
		while (tH)
		{
			if (aMap.find(x - tH->data) != aMap.end())
				soln++;
			tH = tH->next;
		}
		return soln;
	}
};