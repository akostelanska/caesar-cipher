// caesar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <string>
#include <fstream>

using namespace std;

string encrypt(char text[200], int key)
{
    string encrypted = "";

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            if (islower(text[i])) {
                encrypted += (text[i] - 'a' + key) % 26 + 'a';
            }
            if (isupper(text[i])) {
                encrypted += (text[i] - 'A' + key ) % 26 + 'A';
            }
            if (isdigit(text[i])) {
                encrypted += (text[i] - '0' + key) % 10 + '0';
            }
        }
        else  
            encrypted += " ";
    }
   ofstream Output("output.txt");
   Output << "Encrypted message: " << encrypted << "\n";
   Output.close();

    return encrypted;
}

int main() {
    char text[200];
    int key;

    ofstream Input("input.txt");

    cout << "Enter message: " << endl;
    cin.getline(text, sizeof(text)); 

    cout << "Enter key: " << endl;
    cin >> key;

    Input << "Original message: " << text << "\n" << "Key: " << key << "\n";

    cout << "Encrypted text: " << encrypt(text, key) << endl;

    Input.close();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
