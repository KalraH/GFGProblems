#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	We traverse the array & for each element we calculate the possible inversions in the array.
 */
class Solution
{
public:
	long long int inversionCount(long long arr[], int n)
	{
		long long int soln = 0;
		for (int i = 0; i < n; i++)
			for (int j = (i + 1); j < n; j++)
				if (arr[i] > arr[j])
					soln++;
					
		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N), S: O(1)
 *
 * @def 	Optimal Solution. USING MERGE SORT !!
 *
 * @details 	We perform the merge sort into the array. We split the array into parts untill the left & right halfs are left with 1 element each & then, just before 
 * 		merging, we use a logic to count the No. of inversions as if the left & right arrays are sorted within itself, then if I get an element in left array
 * 		which is bigger than an element in right array, we can say all the elements to the right of the ele in left array also forms inversions with the same
 * 		ele in the right array. So, we increment the inversion count accordingly at each merging step & find the answer.
 */
class Solution
{
private:
	void merge(vector<int> &nums, int low, int mid, int high)
	{
		int left = low, right = (mid + 1);
		vector<int> temp;

		while ((left <= mid) && (right <= high))
		{
			if (nums[left] <= nums[right])
				temp.push_back(nums[left++]);
			else
			{
				soln += (mid - left + 1);
				temp.push_back(nums[right++]);
			}
		}

		while (left <= mid)
		temp.push_back(nums[left++]);

		while (right <= high)
		temp.push_back(nums[right++]);
		
		for (int  i = low; i <= high; i++)
			nums[i] = temp[i - low];

		return;
	}

	void mergeSort(vector<int> &nums, int low, int high)
	{
		if (low == high)
			return;
		
		int mid = (low + high) / 2;

		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);

		merge(nums, low, mid, high);

		return;
	}

public:
	int soln = 0;
	
	int inversionCount(vector<int> &arr)
	{
		mergeSort(arr, 0, arr.size() - 1);

		return soln;
	}
};