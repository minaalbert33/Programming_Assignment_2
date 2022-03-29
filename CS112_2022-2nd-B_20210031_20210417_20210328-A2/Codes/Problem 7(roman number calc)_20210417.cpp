/* Author : Mina Albert Saeed
 * Course : CS 112
 * Instructor: Dr. Mohammad El-Ramly
 * Assignment : Assignment 2 – Version 5.0
 *
 * */

#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
#include<iomanip>
#include<regex>
using namespace std;

bool isValidRoman(string);
int romanValue(char);

int main() {
    string romanNum;
    for(;;){
    // looping till find valid Roman Number.
        for(;;){
        cout << "Enter a Roman Number to be converted: ";
        cin >> romanNum;

            if(!isValidRoman(romanNum)){
                cout << "Invalid Roman Number. " << endl;
                continue;
            }else break;
        }

        int arabicNum = 0, p = 0;
        for(int i = romanNum.size()-1; i >= 0; i--) {
            if(romanValue(romanNum[i]) >= p)
                arabicNum += romanValue(romanNum[i]);
            else
                arabicNum -= romanValue(romanNum[i]);

            p = romanValue(romanNum[i]);
        }

    cout << "Arabic Number:" << arabicNum << endl;
    cout << "Want to exit ? press 0, otherwise press any thing: ";
    cin >> arabicNum;
    if(arabicNum == 0) break; else continue;
    }
}
// IV


// to check for validaity of the input
bool isValidRoman(string str){
    regex regRoman("M{0,3}(C[DM]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})");
    return regex_match(str, regRoman);
}

// returning the value of the char.
int romanValue(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1'000;
    }
}
