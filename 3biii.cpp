#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double balance, totalCost, surcharge, vat, finalCost;
    int units;
    char choice;

    do {
        // Input user balance and water units used
        cout << "Enter your account balance (UGX): ";
        cin >> balance;

        cout << "Enter the number of water units used: ";
        cin >> units;

        // Calculate the cost based on water usage
        double cost = 0;

        if (units <= 10) {
            cost = units * 150; // First 10 units
        } else if (units <= 20) {
            cost = (10 * 150) + ((units - 10) * 175); // Next 10 units
        } else {
            cost = (10 * 150) + (10 * 175) + ((units - 20) * 200); // Units beyond 20
        }

        // Apply the surcharge of 15%
        surcharge = cost * 0.15;
        totalCost = cost + surcharge;

        // Apply VAT of 18%
        vat = totalCost * 0.18;
        finalCost = totalCost + vat;

        // Check if the user has sufficient balance
        if (finalCost > balance) {
            cout << "Error: Insufficient balance." << endl;
            cout << "Remaining balance before usage: " << fixed << setprecision(2) << balance << " UGX" << endl;
        } else {
            // Deduct from balance and display final amount
            balance -= finalCost;
            cout << "Total cost after surcharge and VAT: " << fixed << setprecision(2) << finalCost << " UGX" << endl;
            cout << "Remaining balance after usage: " << fixed << setprecision(2) << balance << " UGX" << endl;
        }

        // Ask the user if they want to perform another calculation
        cout << "Do you want to calculate for another user? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // Loop until user chooses not to continue

    cout << "Thank you for using the water billing system!" << endl;

    return 0;
}

