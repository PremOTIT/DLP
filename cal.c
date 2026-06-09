#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

// Function to clear invalid input
void clearInput() {
    cin.clear(); // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
}

int main() {
    double num1, num2;
    char op;

    cout << "===== Simple C++ Calculator =====" << endl;

    // Input first number
    cout << "Enter first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a number: ";
        clearInput();
    }

    // Input operator
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "Invalid operator. Please enter (+, -, *, /): ";
        cin >> op;
    }

    // Input second number
    cout << "Enter second number: ";
    while (!(cin >> num2)) {
        cout << "Invalid input. Please enter a number: ";
        clearInput();
    }

    // Perform calculation
    double result;
    bool validOperation = true;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
                validOperation = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            validOperation = false; // Should not happen due to earlier validation
    }

    // Display result
    if (validOperation) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
