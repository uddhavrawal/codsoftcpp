#include <iostream>

using namespace std;

 
double add(double x, double y) {
    return x + y;
}
 
double subtract(double x, double y) {
    return x - y;
}
 
double multiply(double x, double y) {
    return x * y;
}
 
double divide(double x, double y) {
    if (y == 0) {
        cout << "Cannot divide by zero" << endl;
        return 0.0;  // You can choose to return any value here
    }
    return x / y;
}

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    double result;

    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            cout << "Invalid operation" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}
