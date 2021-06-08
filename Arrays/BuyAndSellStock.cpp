
#include<iostream>
using namespace std;

//In this problem we have to find the maxprofit that we can do after buying at minimal price and selling at maximal price.
// We just iterate through loop and find the minimum price and then we are subtracting it with the remaining prices in array so as to get the maximum profit.

int maximizeProfit(int arr[], int len) {

    int minPrice = arr[0];
    int profit = 0;
    int maxProfit = 0;

    for (int i = 0; i < len; ++i) {

        minPrice = min(minPrice, arr[i]);
        profit = arr[i] - minPrice;

        maxProfit = max(maxProfit, profit);

    }

    return maxProfit;
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

    int result = maximizeProfit(A, n);

    cout << "Maximize profit after buying and selling is : " << result;
}

