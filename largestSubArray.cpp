// C++ program to find largest subarray with equal number of
// 0's and 1's.

#include <bits/stdc++.h>
using namespace std;

// Returns largest subarray with equal number of 0s and 1s

int maxLen(int arr[], int n)
{

	unordered_map<int, int> hM;

	int sum = 0; // Initialize sum of elements
	int max_len = 0; // Initialize result
	int ending_index = -1;

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == 0) ? -1 : 1;


	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (sum == 0) {
			max_len = i + 1;
			ending_index = i;
		}

		if (hM.find(sum) != hM.end()) {
			if (max_len < i - hM[sum]) {
				max_len = i - hM[sum];
				ending_index = i;
			}
		}
		else
			hM[sum] = i;
	}

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == -1) ? 0 : 1;

	printf("%d to %d\n",
		ending_index - max_len + 1, ending_index);

	return max_len;
}


int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	maxLen(arr, n);
	return 0;
}

