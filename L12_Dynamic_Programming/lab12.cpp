#include <iostream>
#include <chrono>
#include <random> 

using namespace std;

int memoArr[1000] = {0};


int naiveFibonacci(int n) {
    if(n <= 1){
        return n;
    }

    return naiveFibonacci(n-1) + naiveFibonacci(n-2);
}

int memoFibonacci(int n){
    if(memoArr[n] != 0){
        return memoArr[n];
    }

    memoArr[n] = memoFibonacci(n-1) + memoFibonacci(n-2); 
    return memoArr[n];
}

int main(){
    // Fibonacci comparisons - Memoisation - Top-Down DP
    {
        memoArr[0] = 1;
        memoArr[1] = 1;
        int n = 5;

        /*
        auto start = chrono::high_resolution_clock::now();
        naiveFibonacci(n);
        auto end = chrono::high_resolution_clock::now();
        cout << "Runtime: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
        */

        auto start = chrono::high_resolution_clock::now();
        cout << memoFibonacci(n) << endl;
        auto end = chrono::high_resolution_clock::now();
        cout << "Runtime: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
        system("pause");
    }

    // Least amount of coins - Tabulation - Bottom-Up DP
    {
        int amount;
        cout << "Enter the amount to make change for: ";
        cin >> amount;
        int coinSize = 3;
        int coins[coinSize] = {1, 4, 5};
        int coinCount[coinSize] = {0};
        int dpTab[amount + 1] = {0};

        // NAIVE
        {
            int amountCopy = amount;
            int ans = 0;
            for(int i = coinSize - 1; i >= 0; --i){
                ans += amountCopy / coins[i];
                amountCopy %= coins[i];
            }

            cout << "We've given change for " << amount << " cents using the least amount of coins: " << ans << endl;
        }

        // DYNAMIC PROGRAMMING
        {
            for(int i = 1; i < amount + 1; ++i){
                dpTab[i] = INT_MAX;
            }

            for(int i = 1; i <= amount; i++){
                for(int j = 0; j < coinSize; j++){
                    if(coins[j] <= i){
                        dpTab[i] = min(dpTab[i], dpTab[i - coins[j]] + 1);
                    }
                }
            }

            cout << "We've given change for " << amount << "cents using the least amount of coins: " << dpTab[amount] << endl;
        }
        
        system("pause");
    }

    // 0/1 Knapsack Problem - 2d DP Table
    {
        int items = 20;
        int values[items];
        int weights[items];

        srand(time(0));

        for(int i = 0; i < 20; i++) {
            values[i] = rand() % 100 + 1; // Random value between 1 and 100
            weights[i] = rand() % 20 + 1; // Random weight between 1 and 25
        }

        for(int i = 0; i < 20; i++) {
            cout << "Item " << i + 1 << ": Value = " << values[i] << ", Weight = " << weights[i] << endl;
        }

        int capacity = 35;

        int dpTab[items + 1][(int)capacity + 1] = {0};

        for(int i = 1; i <= items; i++){
            for(int j = 0; j <= capacity; j++){
                if(weights[i - 1] <= j){
                    dpTab[i][j] = max(dpTab[i -1][j], dpTab[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
                else{
                    dpTab[i][j] = dpTab[i - 1][j];
                }
            }
        }

        cout << "Knapsack capacity reached." << endl;
        cout << "Total value plundered: " << dpTab[items][capacity]  << "$" << endl;
    }
    
    return 0;
}