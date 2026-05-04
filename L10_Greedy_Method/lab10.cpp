#include <iostream>
#include <random>

using namespace std;



// ------------------------ Main function ------------------------
int main() {
    // FRACTIONAL KNAPSACK PROBLEM
    {
        double values[20];
        double weights[20];

        srand(time(0));

        for(int i = 0; i < 20; i++) {
            values[i] = rand() % 100 + 1; // Random value between 1 and 100
            weights[i] = rand() % 25 + 1; // Random weight between 1 and 25
        }

        for(int i = 0; i < 20; i++) {
            cout << "Item " << i + 1 << ": Value = " << values[i] << ", Weight = " << weights[i] << endl;
        }

        double capacity;
        cout << "Enter the capacity of the knapsack: ";
        cin >> capacity;

        for(int i = 0; i < 19; i++){
            for(int j = i + 1; j < 20; j++){
                if(values[i] / weights[i] < values[j] / weights[j]){
                    swap(values[i], values[j]);
                    swap(weights[i], weights[j]);
                }
            }
        }

        double totalValue = 0;
        int i = 0;
        while(capacity > 0){
            double taken = min(weights[i], capacity);
            cout << "Added item with value " << values[i] << "$ with " << taken << " taken amount." << endl;
            totalValue += values[i] * taken;
            capacity -= taken;
            ++i;
        }

        cout << "Knapsack capacity reached." << endl;
        cout << "Total value plundered: " << totalValue  << "$" << endl;

        system("pause");
    }

    // LEAST AMOUNT OF COINS PROBLEM
    {
        int amount;
        cout << "Enter the amount to make change for: ";
        cin >> amount;

        int coins[4] = {50, 10, 5, 1};
        int coinCount[4] = {0};
        for(int i = 0; i < 4; i++){
            while(coins[i] <= amount){
                coinCount[i]++;
                amount -= coins[i];
            }
        }

        cout << "We've given change for " << amount << "c using the least amount of coins:" << endl;
        for(int i = 0; i < 4; i++){
            cout << coins[i] << "c: " << coinCount[i] << " coin(s)" << endl;
        }
        system("pause");
    }

    // TIME SCHEDULING PROBLEM
    {
        int start[20];
        int end[20];
        for(int i = 0; i < 20; ++i){
            start[i] = rand() %  1440 + 1;
            end[i] = start[i] + rand() % 300;
        }

        for(int i = 0; i < 20; ++i){
            for(int j = i + 1; j < 20; ++j){
                if(end[i] > end[j]){
                    swap(start[i], start[j]);
                    swap(end[i], end[j]);
                }
            }
        }

        for(int i = 0; i < 20; ++i){
            cout << "Activity " << i + 1 << ": Start = " << start[i] << " min, End = " << end[i] << " min" << endl;
        }

        int count = 0;
        int lastEnd = 0;
        for(int i = 0; i < 20; ++i){
            if(start[i] >= lastEnd){
                count++;
                lastEnd = end[i];
            }
        }
        cout << "Maximum number of booked activities: " << count << endl;
        system("pause");
    }

    return 0;
}