
#include<iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {

    int i,j,k, invCount = 0;
    i = left;
    j = mid;
    k = left;

    while((i <= mid-1) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount = invCount + (mid-i);
        }
    }

    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSort(int arr[], int temp[], int left, int right) {

    int mid, invCount = 0;
    if(left < right) {
        mid = left + ((right - left) / 2);

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid + 1, right);

    }
    return invCount;
}

void findCountInversions(int arr[], int len) {

    int temp[len];

    int answer = mergeSort(arr, temp, 0, len-1);

    cout << "Inversion Count = " << answer <<'\n';
}

int main() {

    cout << "Enter the number of elements" << '\n';
    int n;
    cin >> n;

    int A[n];
    cout << "Enter elements: " <<'\n';
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    findCountInversions(A, n);
}

