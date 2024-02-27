/**
 * @brief 	Approach-1: T: O(N), S: O(1) 
 *
 * @def		Simple Bruteforce.
 *
 * @details 	Just iterate through whole array & keep updating it at run time with the value arr[i] = (arr[i] OR arr[i+1]). 
 * 		Just make sure to iterate till last second element of array.
 */
int* game_with_number(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++)
        arr[i] = (arr[i] | arr[i+1]);

    return arr;
}