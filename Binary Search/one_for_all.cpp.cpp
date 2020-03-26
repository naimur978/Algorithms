#include <bits/stdc++.h>

using namespace std;

int binarySearch(int array[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    //as array must be in sorted form
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (array[middle] == target)
            return middle;
        else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, n , x);

    // If element is not present
    if (ind == -1)
        return 0;

    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;

    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;

    return count;
}

/* Binary Search finding the first occurence of target */
int binarySearchFirst(int array[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int first = -1;


    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (array[middle] == target)
        {
            first = middle;
            high = middle - 1;
        }
        else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return first;
}

/* Binary Search finding the last occurence of target */
int binarySearchLast(int *array, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (array[middle] == target)
        {
            last = middle;
            low = middle + 1;
        }
        else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return last;
}

int findRotationCount(int arr[], int low, int high)
{


	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// if the search space is already sorted, we have
		// found the minimum element (at index low)
		if (arr[low] <= arr[high])
			return low;

		int mid = (low + high) / 2;

		// find next and previous element of the mid element
		// (in circular manner)
		int next = mid + 1;
		int prev = mid - 1 ;

		// if mid element is less than both its next and previous
		// neighbor, then it is the minimum element of the array

		if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
			return mid;

		// if arr[mid..high] is sorted and mid is not the minimum element,
		// then pivot element cannot be present in arr[mid..high] and
		// we can discard arr[mid..high] and search in the left half

		else if (arr[mid] <= arr[high])
			high = mid - 1;

		// if arr[low..mid] is sorted then pivot element cannot be present in
		// it and we can discard arr[low..mid] and search in the right half

		else if (arr[mid] >= arr[low])
			low = mid + 1;
	}

	// invalid input
	return -1;
}

int smallestMissing(int arr[], int low, int high)
{
	// base condition
	if (low > high)
		return low;

	int mid = low + (high - low) / 2;

	// if mid index matches with the mid element, then the mismatch
	// lies on the right half
	if (arr[mid] == mid)
		return smallestMissing(arr, mid + 1, high);
	else
		// mismatch lies on the left half
		return smallestMissing(arr, low, mid - 1);
}




int getCeil(int arr[], int n, int x)
{
	// search space is A[low..high]
	int low = 0, high = n - 1, mid;

	// initialize ceil to -1
	int ceil = -1;

	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// find the mid value in the search space
		mid = (low + high) / 2;

		// if x is equal to mid element, it is the ceil
		if (arr[mid] == x)
			return arr[mid];

		// if x is less than the mid element, ceil exists in the
		// sub-array A[low..mid]. We update ceil to the mid element
		// and reduce our search space to left subarray A[low..mid-1]
		else if (x < arr[mid])
		{
			ceil = arr[mid];
			high = mid - 1;
		}

		// if x is more than the mid element, ceil exists in the
		// right sub-array A[mid+1..high]
		else
			low = mid + 1;
	}

	return ceil;
}

// Function to find floor of x in sorted array arr[0..n-1]
// i.e. largest integer less than or equal to x
int getFloor(int arr[], int n, int x)
{
	int low = 0, high = n - 1, mid;

	// initialize floor to -1
	int floor = -1;

	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// find the mid value in the search space
		mid = (low + high) / 2;

		// if x is equal to mid element, it is the floor
		if (arr[mid] == x)
			return arr[mid];

		// if x is less than the mid element, floor exists in the left
		// sub-array A[low..mid-1]
		else if (x < arr[mid])
			high = mid - 1;

		// if x is more than the mid element, floor exists in the
		// sub-array A[mid..high]. We update floor to the mid element
		// and reduce our search space to right subarray A[mid+1..high]
		else
		{
			floor = arr[mid];
			low = mid + 1;
		}
	}

	return floor;
}



int main()
{
    int array[] = {0, 1, 12, 48, 49, 49, 49, 50, 50, 65, 89};
    int n = sizeof(array)/sizeof(array[0]);
    int low = 0, high = n - 1;

    /// Regular Binary Search
    cout << "Value(65) found at Index: " << binarySearch(array, n, 65) << endl;

    /// Binary Search finding first occurence of duplicate values
    cout << "Value found at first Index: " << binarySearchFirst(array, n, 49) << endl;

    /// Binary Search finding last occurence of duplicate values
    cout << "Value found at last Index: " << binarySearchLast(array, n, 49) << endl;

    ///smallest missing value
	cout<<"The smallest missing value is "<<smallestMissing(array, low, high)<<endl;

	//count of an element
	int x = 49;
    cout <<"Number of occurences of "<<x<<" is : "<< countOccurrences(array, n, x)<<endl;

	///ceiling and floor of a value
	for (int i = 0; i <= 10; i++)
	{
		printf("Number %d -> ", i);
		printf("ceiling is %d, ", getCeil(array, n, i));
		printf("floor is %d\n", getFloor(array, n, i));
	}


    ///rotation count of unorganized array
    int arr[] = { 8, 9, 10, 2, 5, 6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int highnum= num-1;
	int count = findRotationCount(arr, low, highnum);
	printf("The array is rotated %d times\n", count);

	//highest value from an array
	if(count==0)
        cout<<"The highest value is : "<<arr[n-1]<<endl;
    else
        cout<<"The highest value is : "<<arr[count-1]<<endl;



    return 0;
}
