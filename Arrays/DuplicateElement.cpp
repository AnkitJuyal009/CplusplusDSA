
#include<iostream>
#include<bitset>
using namespace std;


void findDuplicateElement(int arr[], int len) {

    int result = 0;

    for (int i = 0; i < len; ++i) {

        arr[abs(arr[i])] *= -1;

        if(arr[abs(arr[i])] > 0) {
            result = abs(arr[i]);
            break;
        }
    }

    cout << "The duplicate element is : " << result <<'\n';

}

void findDuplicateElementByBitSet(int arr[], int len) {

    bitset<100001> bset(0);

    for (int i = 0; i < len; ++i) {

        if(bset[arr[i]] == 0) {
            bset[arr[i]] = true;
        }
        else {
            cout << "The duplicate element using bitset is : " << arr[i] <<'\n';
            break;
        }
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

//    findDuplicateElementByBitSet(A, n);
    findDuplicateElement(A, n);




}




