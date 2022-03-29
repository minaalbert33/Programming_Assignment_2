#include <iostream>
#include <string>
#include<limits>
using namespace std;
int secretLetter()   // for inputing secretnletter
{
	char letter = ':';
	string test;
	while (letter < 65 || letter > 122) {      // Loops until a letter is entered
		cout << "Enter the secret letter: ";
		getline(cin, test);
		if (test.length() == 1) {        // checking for entering only one letter
			letter = test[0];
		}
	}
	return int(letter);        // Returns the ASCII value of the letter
}


int cipher()      // for ciphering the message
{
	int secret = secretLetter();       // Stores the ASCII value of the letter   
	string ciphered = "", message;
	cout << "Enter the message you want to cipher: ";
	getline(cin, message);        // inputing the message
	
	for (int i = 0; i < message.length(); i++) {   // For each letter in the message
		ciphered += char((secret ^ int(message[i])) + 96);  // XOR the secret letter and the current letter of the message
	}													    // Store each ciphered character in the string 
	cout << "Ciphered text: " << ciphered << "  (Hexa ";   // Print the ciphered message

	for (int i = 0; i < message.length(); i++) {    // For each letter in the message
		cout << hex << (secret ^ int(message[i])) + 96;   // Print the hex of the result of XOR
	}
	cout << ")\n\n";
	return 0;
}

int decipher()              // Function to decipher the ciphered text (input in the form of text)
{
	int secret = secretLetter();
	string deciphered = "", text;
	cout << "Enter the text you want to decipher: ";
	getline(cin, text);       // Take the ciphered text to be deciphered

	for (int i = 0; i < text.length(); i++) {
		deciphered += char( (int(text[i]) - 96) ^ secret );    // XOR the secret letter and the current letter of the text
	}														   // Store each deciphered character in the string variable
	cout << "Deciphered text: " << deciphered << endl << endl;  // Print the deciphered message
	return 0; 
}

int decipher_hex()				// Function to decipher the ciphered text (input in the form of hexadecimal)
{
	int secret = secretLetter(), hex;
	string deciphered = "", text, sub;
	cout << "Enter the hexadecimal you want to decipher: ";
	getline(cin, text);				// Take the hexadecimal input

	for (int i = 0; i < text.length(); i += 2) {
		sub = text.substr(i, 2);      // Take a substring of the input of length 2 
		hex = stoi(sub, 0, 16);       // Turn the hexadecimal string to a decimal integer
		deciphered += char( (hex - 96) ^ secret );  // XOR  the decimal value of the current character with the secret letter
	}
	cout << "Deciphered text: " << deciphered << endl << endl;  // Print the deciphered message
	return 0;
}


int main() 
{
	int process = 0;
	while (process != 3) {          // Loops until the user chooses 
		cout << "Please enter the number of what you want to do\n";
		cout << "1- Cipher a message\n";
		cout << "2- Decipher a message\n";
		cout << "3- End\n";
		cin >> process;     // Takes the choice of the user
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   // to use the next getline
		
		if (cin.fail()) {       // If the user inputs an invalid 
			cin.clear();        // clear and ignore cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;                // Ask him to choose again
		}      
		
		
		switch (process) {
		case 1:                                  // If the user chose 1 
			cipher();                            // Call the cipher function 
			break;
		
		case 2:                     // If the user chose 2
			int x = 0;
			while (x < 1 || x > 2) {
				cout << "Enter the number of what you want to do\n";    // Asking what do you want to do with the program
				cout << "1- Decipher text\n";
				cout << "2- Decipher hexa\n";
				cin >> x;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (cin.fail()) {             // If the user inputs an invalid value
					cin.clear();              // clear and ignore cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			switch (x) {
			case 1:         // If the chosen num is 1 
				decipher();   // call the decipher function using text
				break;
			case 2:         // If the chosen num is 2 
				decipher_hex();    // call the decipher function using text 
				break;
			}
			break;
		}
	}
}
