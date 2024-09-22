#include <iostream>
#include <iomanip>

using namespace std;

// Function to calculate total cost based on tiered pricing
double calculateTotalCost(int units) {
    double totalCost = 0.0;

    if (units <= 10) {
        totalCost = units * 150; // First 10 units
    } else if (units <= 20) {
        totalCost = (10 * 150) + ((units - 10) * 175); // Next 10 units
    } else {
        totalCost = (10 * 150) + (10 * 175) + ((units - 20) * 200); // Beyond 20 units
    }

    // Apply surcharge of 15%
    totalCost *= 1.15;

    return totalCost;
}

// Function to calculate final amount after VAT
double calculateFinalAmount(double totalCost) {
    // Apply VAT of 18%
    return totalCost * 1.18;
}

int main() {
    int waterUnits;
    double accountBalance;
    char continueChoice;

    do {
        cout << "Enter the number of water units used: ";
        cin >> waterUnits;
        
        cout << "Enter your account balance (UGX): ";
        cin >> accountBalance;

        double totalCost = calculateTotalCost(waterUnits);
        double finalAmount = calculateFinalAmount(totalCost);

        cout << fixed << setprecision(2);
        
        if (finalAmount > accountBalance) {
            cout << "Error: Insufficient balance." << endl;
            cout << "Remaining balance before usage: " << accountBalance << " UGX" << endl;
        } else {
            accountBalance -= finalAmount;
            cout << "Total cost after surcharge: " << totalCost << " UGX" << endl;
            cout << "Final amount after VAT: " << finalAmount << " UGX" << endl;
            cout << "Remaining balance after deduction: " << accountBalance << " UGX" << endl;
        }

        // Ask user if they want to continue
        cout << "Do you want to enter another transaction? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Thank you for using the water billing system!" << endl;

    return 0;
}

