
#include<iostream>
using namespace std;

void findCommonElement(int arr1[], int arr2[], int arr3[], int len1, int len2, int len3) {

    int i = 0, j = 0, k = 0;

    cout << "Common elements are : ";

    for (; i < len1 && j < len2 && k < len3 ; ++i,++j,++k) {

        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else if(arr2[j] < arr3[k])
            j++;
        else
            k++;
    }

    cout << '\n';
}

int main() {

    int a, b, c;
    cout << "Enter number of elements of 3 sorted arrays : " << '\n';
    cin >> a >> b >> c;

    int A[a], B[b], C[c];

    cout << "Elements in A : " << '\n';

    for (int i = 0; i < a; ++i) {
        cin >> A[i];
    }

    cout << "Elements in B : " << '\n';

    for (int i = 0; i < b; ++i) {
        cin >> B[i];
    }

    cout << "Elements in C : " << '\n';


    for (int i = 0; i < c; ++i) {
        cin >> C[i];
    }

    findCommonElement(A, B, C, a, b, c);
}

