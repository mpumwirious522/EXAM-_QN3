#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Define constants for pricing
    const double FIRST_TEN_RATE = 150.0;
    const double NEXT_TEN_RATE = 175.0;
    const double ADDITIONAL_RATE = 200.0;
    const double SURCHARGE_RATE = 0.15; // 15%
    const double VAT_RATE = 0.18; // 18%

    while (true) {
        // User inputs
        double balance, totalCost = 0.0, surcharge, vat;
        int waterUnits;

        // Input user balance and water units used
        cout << "Enter your balance (UGX) or -1 to exit: ";
        cin >> balance;

        // Exit condition
        if (balance == -1) {
            cout << "Exiting the program." << endl;
            break; // Exit the loop
        }

        cout << "Enter water units used: ";
        cin >> waterUnits;

        // Calculate total cost based on water units used
        if (waterUnits <= 10) {
            totalCost = waterUnits * FIRST_TEN_RATE;
        } else if (waterUnits <= 20) {
            totalCost = (10 * FIRST_TEN_RATE) + ((waterUnits - 10) * NEXT_TEN_RATE);
        } else {
            totalCost = (10 * FIRST_TEN_RATE) + (10 * NEXT_TEN_RATE) + ((waterUnits - 20) * ADDITIONAL_RATE);
        }

        // Calculate surcharge and VAT
        surcharge = totalCost * SURCHARGE_RATE;
        vat = totalCost * VAT_RATE;

        // Total cost after adding surcharge and VAT
        totalCost += surcharge + vat;

        // Check if the balance is sufficient
        if (balance >= totalCost) {
            balance -= totalCost; // Deduct total cost from balance
            cout << fixed << setprecision(2);
            cout << "Total cost after surcharge and VAT: " << totalCost << " UGX" << endl;
            cout << "Remaining balance: " << balance << " UGX" << endl;
        } else {
            cout << "Error: Insufficient balance." << endl;
            cout << "Remaining balance before usage: " << balance << " UGX" << endl;
        }

        cout << endl; // Print a new line for better readability
    }

    return 0;
}

