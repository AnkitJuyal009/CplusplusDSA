
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

//find kth smallest element in an unsorted array

//Randomized quickselect used where we just randomly make a pivot element using rand function and just sort around that pivot element in partition function
//after getting the sorted elements we return the index of pivot element and check if it is equal to k, or greater or smaller in kthSmallest function.

//TC => O(n)

int partition(int arr[], int l, int r) {

    int x = arr[r];
    int i = l;

    for (int j = l; j <= r-1; ++j) {

        if(arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r) {

    int n = r - l + 1;

    int pivot = rand() % n;

    swap(arr[l+pivot], arr[r]);

    return partition(arr, l , r);

}

int kthSmallest(int arr[], int l, int r, int k) {

    int pos = randomPartition(arr, l, r);

    if(pos-l == k-1)
        return arr[pos];
    if(pos-l > k-1)
        return kthSmallest(arr,l,pos-1,k);
    else
        return kthSmallest(arr,pos+1,r,k-pos+l-1);

    return INT_MAX;
}

int main()
{
    cout << "Enter the number of elements and value of k" << '\n';
    int n,k;
    cin >> n >> k;

    int A[n];
    cout << "Enter elements: " <<'\n';
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout <<"Kth smallest element is " << kthSmallest(A, 0, n-1, k);
    return 0;
}

