
#include<iostream>
#include <algorithm>

//In this problem, we first sort the array and then find the largest and smallest by adding and subtracting k respectively

//TC => O(nlogn)

using namespace std;

int MinimizeHeight(int arr[], int len, int high) {

    sort(arr, arr + len);
    int largest, smallest;
    int result = arr[len-1] - arr[0];

    for (int i = 1; i <= len-1; ++i) {

        if(arr[i] >= high) {
            largest = max(arr[i - 1] + high, arr[len - 1] - high);
            smallest = min(arr[0] + high, arr[i] - high);

            result = min(result, largest - smallest);
        }
        else continue;
    }

    return result;
}

int main() {

    cout << "Enter the number of elements and the value of height" << '\n';
    int n, k;
    cin >> n >> k;

    int A[n];
    cout << "Enter elements: " <<'\n';
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int ans = MinimizeHeight(A, n, k);

    cout << "Minimized height is : " << ans <<'\n';
}

