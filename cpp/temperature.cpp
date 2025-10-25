#include<iostream>

using namespace std;

int main() {
    unsigned short choice;
    float input_temperature;
    while(true) {
        cout << "Temperature Converter" << endl;
        cout << "1.\tCelsius to Fahrenheit" << endl;
        cout << "2.\tFahrenheit to Celsius" << endl;
        cout << "3.\tExit" << endl;
        cout << "Enter you choice (1-3): ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter temperature in Celsius: ";
            cin >> input_temperature;
            cout << input_temperature << " C" << " = " << input_temperature * (9/5) + 32 << " F";
        } else if (choice == 2) {
            cout << "Enter temperature in Fahrenheit: ";
            cin >> input_temperature;
            cout << input_temperature << " F" << " = " << (input_temperature - 32) * (5/9) << " C";
        } else if (choice == 3) {
            cout << "Exiting temperature converter.";
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
