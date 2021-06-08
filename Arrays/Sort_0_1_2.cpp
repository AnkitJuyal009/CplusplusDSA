
#include<iostream>

using namespace std;

//Sorting the array consisting of 0s,1s and 2s without using sorting algo
//This problem is the variation of dutch national flag problem.
//We can also first store the counts of 0,1 and 2 and then first print 0 then 1 and 2.

//TC => O(n), SC => O(1)

void sortArray(int arr[], int len) {

    int low = 0;
    int mid = 0;
    int high = len - 1;

    while (mid <= high) {
        switch (arr[mid]) {

            // If the element is 0
            case 0:
                swap(arr[low++], arr[mid++]);
                break;

                // If the element is 1 .
            case 1:
                mid++;
                break;

                // If the element is 2
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}


void printArray(int arr[], int len) {

    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
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

    sortArray(A, n);
    printArray(A, n);
}