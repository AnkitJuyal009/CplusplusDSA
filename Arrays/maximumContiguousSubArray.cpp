
#include<iostream>
using namespace std;

//This problem is based on Kadane's Algorithm.

//TC => O(n)

void computeMaximumContiguousSubArray(int arr[], int n) {

    int maxSum = 0, maxSum_so_far = 0;

    for (int i = 0; i < n; ++i) {

        maxSum_so_far += arr[i];

        if(maxSum_so_far > maxSum) {
            maxSum = maxSum_so_far;
        }
    }

    cout << "Maximum COntiguous SubArray Sum is : " << maxSum;
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

    computeMaximumContiguousSubArray(A, n);
}

