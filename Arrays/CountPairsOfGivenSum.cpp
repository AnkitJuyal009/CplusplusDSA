
#include<iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void countPairsUsingTwoPointer(int arr[], int len, int sum) {

    int i = 0;
    int j = len-1;
    int result = 0;

    sort(arr, arr + len);

    while(i < j) {
        if(arr[i] + arr[j] > sum) {
            j--;
        }
        else if(arr[i] + arr[j] < sum) {
            i++;
        }
        else {
            int x = arr[i];
            int fx = i;
            while(i < j && arr[i] == x)
                i++;

            int y = arr[j];
            int fy = j;
            while(j >= i && arr[j] == y)
                j--;

            //If both are same
            if(x == y) {
                //remove the extra counted numbers
                int leftOut = ((i - fx) + (y - fy) - 1);
                 result += (leftOut * (leftOut + 1)) / 2;
            }
            else
                result += (i - fx) * (fy - j);
        }
    }

    cout << "The count pairs with given sum is : " << result << '\n';
}

void countPairsUsingMap(int arr[], int len, int sum) {

    unordered_map<int,int> map;
    int count = 0;

    for (int i = 0; i < len; ++i) {

        int num = sum - arr[i];

        if(map[num] == 0) {
            map[arr[i]]++;
        }
        else {
            count += map[num];
            map[arr[i]]++;
        }
    }

    cout << "The count pairs with given sum is : " << count << '\n';
}

int main() {

    cout << "Enter the number of elements and sum" << '\n';
    int n, k;
    cin >> n >> k;

    int A[n];
    cout << "Enter elements: " <<'\n';
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    countPairsUsingMap(A, n, k);
    countPairsUsingTwoPointer(A, n, k);
}