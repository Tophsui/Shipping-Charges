#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

// Function to calculate shipping charges
double calculateShippingCharges(double weight, double distance) {
    double rate;

    // Determine the rate based on the weight of the package
    if (weight <= 2.0) {
        rate = 1.10;
    }
    else if (weight <= 6.0) {
        rate = 2.20;
    }
    else if (weight <= 10.0) {
        rate = 3.70;
    }
    else if (weight <= 20.0) {
        rate = 4.80;
    }
    else {
        // This case should never happen due to input validation
        return 0.0;
    }

    // Calculate total charges
    return (distance / 500) * rate;
}

int main() {
    double weight, distance;

    // Get user input for weight
    cout << "Enter the weight of the package (in kg, between 0 and 20): ";
    cin >> weight;

    // Input validation for weight
    while (weight <= 0 || weight > 20) {
        cout << "Invalid weight. Please enter a weight greater than 0 and less than or equal to 20 kg: ";
        cin >> weight;
    }

    // Get user input for distance
    cout << "Enter the distance to ship the package (in miles, between 10 and 3000): ";
    cin >> distance;

    // Input validation for distance
    while (distance < 10 || distance > 3000) {
        cout << "Invalid distance. Please enter a distance between 10 and 3000 miles: ";
        cin >> distance;
    }

    // Calculate shipping charges
    double charges = calculateShippingCharges(weight, distance);

    // Display the charges
    cout << fixed << setprecision(2); // Format to 2 decimal places
    cout << "The shipping charges are: $" << charges << endl;

    return 0;
}
