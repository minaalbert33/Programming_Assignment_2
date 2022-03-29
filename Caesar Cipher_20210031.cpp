// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Caesar Cipher_20210031.cpp
// Program Description: 
	//It is a type of
	//substitution cipher in which each letter in the plaintext is replaced by a letter at some fixed number
	//of positions down the alphabet
// Last Modification Date: 23/03/2022
// Author1 and ID and Group: 20210031 	Group :B
// Teaching Assistant: Dr. Mohammad El-Ramly
// Purpose: To solve cipher problem

#include <iostream>
using namespace std;

// This function to check if shift is valid or no 

int validate_shift(int shift)
{
	// Take out cycles by taking number modulus 26
    shift %= 26;
	// And also check if shift has negative_sign to increment by 26
    if(shift < 0)
        shift += 26;
    return shift;
}

//This function take two parameters text and shift value and encrypt text
string encrypt(string text, int shift)
{
	// Declaring empty variable to store answer
    string answer = "";
	// Looping through text size
    for (int i = 0; i < text.size(); ++i) {
		// Check if charcter is Capital or small
        if(isupper(text[i]))
        {
			// Get ascii code of current character
            int ascii_code = text[i];
			// Here increment ascii code by shift value then,
			// Decrement it by 65 to get ith character in alphabetical order
			// Also take modulus 26 to remove any cycles
            ascii_code = (ascii_code + shift - 65) % 26;
			// After all that, Increment again by 65 to convert ith character into ascii code
            answer += char(ascii_code + 65);
        }
        else
        {
			// Same we did in Capital character but, change 65 by 97
			// Because in upper 'A' = 65, but in lower 'a' = 97
            int ascii_code = text[i];
            ascii_code = (ascii_code + shift - 97) % 26;
            answer += char(ascii_code + 97);
        }
    }
	// I return answer text to print it
    return answer;
}

//This function take two parameters text and shift value and decrypt text
string decrypt(string text, int shift)
{
    string answer = "";
    for (int i = 0; i < text.size(); ++i) {
        if(isupper(text[i]))
        {
            int ascii_code = text[i];
            ascii_code = (ascii_code - shift + 65) % 26;
            answer += char(ascii_code + 65);
        }
        else
        {
            int ascii_code = text[i];
            ascii_code = (ascii_code - shift + 97) % 26;
            answer += char(ascii_code + 97);
        }
    }
    return answer;
}
int main() {
    int choice = 0, input_shift;
    string input_text;
    do {
		// Show Current options for the user
        cout<<"Ahlan ya user ya habibi."<<endl;
        cout<<"What do you like to do today?"<<endl;
        cout<<"1- Cipher a message"<<endl;
        cout<<"2- Decipher a message"<<endl;
        cout<<"3- End"<<endl;
		// Take input
        cin>>choice;
        cout<<"Please enter the message to cipher:"<<endl;
        cin>>input_text;
        cout<<"Please enter number of shifting"<<endl;
        cin>>input_shift;
		// Check over all possible Cases
        if(choice == 1)
        {
            int correct_shift = validate_shift(input_shift);
            cout<<encrypt(input_text, correct_shift)<<endl;
        }
        else if (choice == 2)
        {
            int correct_shift = validate_shift(input_shift);
            cout<<decrypt(input_text, correct_shift)<<endl;
        }
        else if (choice == 3)
        {
            cout<<"Bye!\n";
            return 0;
        }
		else
		{
			cout<<"Invalid Input, Please try again"<<endl;
			continue;
		}
    } while (choice != 3);
    return 0;
}
