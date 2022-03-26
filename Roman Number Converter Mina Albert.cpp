#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
#include<iomanip>
#include<regex>
using namespace std;

bool valid_roman(string);
int roman_value(char);

int main() {
    string roman_num;
    for(;;){
    // looping till find valid Roman Number.
        for(;;){
        cout << "Enter a Roman Number to be converted: ";
        cin >> roman_num;

            if(!valid_roman(roman_num)){
                cout << "Invalid Roman Number. " << endl;
                continue;
            }else break;
        }

        int arabic_num = 0, p = 0;
        for(int i = roman_num.size()-1; i >= 0; i--) {
            if(roman_value(roman_num[i]) >= p)
                arabic_num += roman_value(roman_num[i]);
            else
                arabic_num -= roman_value(roman_num[i]);

            p = roman_value(roman_num[i]);
        }

    cout << "Arabic Number:" << arabic_num << endl;
    cout << "Want to exit ? press 0, otherwise press any number: ";
    cin >> arabic_num;
    if(arabic_num == 0) break; else continue;
    }
}

// to check for validaity of the input
bool valid_roman(string str){
    regex reg_roman("M{0,3}(C[DM]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})");
    return regex_match(str, reg_roman);
}

// returning the value of the char.
int roman_value(char c){
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