
#include<iostream>
#include<cmath>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) {
        return 0;
    }

    return (gap/2) + (gap%2);
}

void mergeUsingInsertionSort(int arr1[], int arr2[], int len1, int len2) {

        for (int i = len2 - 1; i >= 0; i--) {
            int j, last = arr1[len1 - 1];
            for (j = len1 - 2; j >= 0 && arr1[j] > arr2[i]; j--)
                arr1[j + 1] = arr1[j];

            // If there was a greater element
            if (j != len1 - 2 || last > arr2[i])
            {
                arr1[j + 1] = arr2[i];
                arr2[i] = last;
            }
        }
}

void mergeTwoSortedArrays(int arr1[], int arr2[], int len1, int len2) {

    int i,j,gap = len1+len2;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {

        for (i = 0; i + gap < len1; ++i) {

            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

            for(j = gap > len1 ? gap - len1 : 0; i < len1 && j < len2; i++, j++) {

                if(arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
            }

            if(j < len2) {
                for (j = 0; j + gap < len2; ++j) {

                    if(arr2[j] > arr2[j+gap])
                        swap(arr2[j], arr2[j+gap]);
                }
            }
        }

    cout << "First Array : ";
    for (int k = 0; k < len1; ++k) {
        cout << arr1[k] << " ";
    }

    cout << '\n';

    cout << "Second Array : ";
    for (int k = 0; k < len2; ++k) {
        cout << arr2[k] << " ";
    }

}

int main() {

    cout << "Enter the number of elements of first and second array" << '\n';
    int m,n;
    cin >> m >> n;

    int A1[m];
    cout << "Enter elements of first array: " <<'\n';
    for (int i = 0; i < m; ++i) {
        cin >> A1[i];
    }

    int A2[n];
    cout << "Enter elements of second array: " <<'\n';
    for (int i = 0; i < n; ++i) {
        cin >> A2[i];
    }

    mergeUsingInsertionSort(A1, A2, m, n);
    mergeTwoSortedArrays(A1, A2, m, n);
}

