// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(log(n))
// Space Complexity : O(1)

https://www.geeksforgeeks.org/search-almost-sorted-array/

int binarySearch(int arr[], int l, int r, int x)
{
while(r >= l)
{
		int mid = l + (r - l) / 2;

    // Handle corner cases carefully
		if (arr[mid] == x)
			return mid;
		if (mid > l && arr[mid - 1] == x)
			return (mid - 1);
		if (mid < r && arr[mid + 1] == x)
			return (mid + 1);

		if (arr[mid] > x)
			r = mid-2;

		else  l = mid+2;
}