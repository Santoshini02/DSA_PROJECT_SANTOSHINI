#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
string generateOTP() {
    string otp = "";
    for (int i = 0; i < 4; ++i) {
        otp += to_string(rand() % 10);
    }
    return otp;
}
int main() {
    srand(time(0)); 

    cout << "OTP Generator"<< endl;

    string otp = generateOTP();
    cout << "Generated OTP: " << otp << endl; 

    string userInput;
    cout << "Enter the OTP to access the system: ";
    cin >> userInput;

    if (userInput == otp) {
        cout << "\n Verification passed" << endl;
    } else {
        cout << "\n Access Denied. Incorrect OTP." << endl;
    }

    return 0;
}