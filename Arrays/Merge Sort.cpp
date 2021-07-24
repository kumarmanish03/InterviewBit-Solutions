// Manish Kumar, IIIT Allahabad

// Merge Sort Algorithm Implementation
// TC	: [Best]Ω(n log(n))	[Average]Θ(n log(n))	[Worst]O(n log(n))


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define OJ \
        freopen("input.txt", "r", stdin); \
        freopen("output.txt", "w", stdout);

void merge(int arr[], int lo, int mid, int hi){
    int lsize = mid - lo + 1;
    int rsize = hi - mid;

    int left[lsize];
    int right[rsize];

    for(int i = 0; i < lsize; i++)
        left[i] = arr[lo + i];
    for(int i = 0; i < rsize; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    // index of merged array
    int k = lo; 
    while(i < lsize && j < rsize){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < lsize){
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < rsize){
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int lo, int hi){
    if(lo >= hi)
        return;
        
    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main(){
    OJ;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}