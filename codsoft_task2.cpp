#include <iostream>
using namespace std;

int main() {
    float a, b, ans;
    char op;
    char cont;

    do {
        cout << "Enter your question (e.g., 5 + 3): ";
        cin >> a >> op >> b;

        switch(op) {
            case '+':
                ans = a + b;
                cout << "Answer: " << a << " + " << b << " = " << ans << endl;
                break;
            case '-':
                ans = a - b;
                cout << "Answer: " << a << " - " << b << " = " << ans << endl;
                break;
            case '*':
                ans = a * b;
                cout << "Answer: " << a << " * " << b << " = " << ans << endl;
                break;
            case '/':
                if (b != 0) {
                    ans = a / b;
                    cout << "Answer: " << a << " / " << b << " = " << ans << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operator. Please use +, -, *, or /." << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
