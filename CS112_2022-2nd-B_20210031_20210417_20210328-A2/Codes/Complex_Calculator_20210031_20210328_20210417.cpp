// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Complex_Calculator_20210031_20210328_20210417.cpp
// Program Description: Program that make Addition, Subtraction,
// Division and Multiplication operations on complex numbers
// Last Modification Date: 03/28/2022
// Author1 and ID and Group: Mina Albert Saeed 20210417 B
// Author2 and ID and Group: Ahmed Zaher 20210031 B
// Author3 and ID and Group: Mohamed Ashraf 20210328 A 
// Teaching Assistant: xxxxx xxxxx
// Purpose: Operation on complex numbers.

#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <complex>
using namespace std;

inline void separateLine(){
    cout << "------------------------------------------------------" << endl;
}

//  check if the operator is valid or not.
bool isValidOperator(char );

//  check if the complex number is valid or not. 
bool isValidCompelxNumber (string& );

//  getting the real && imaginary part of the complex number.
void parse_complex(string , double& , double& );

// Perform operations on the complex numbers.
void calc(char , complex <double> , complex <double> , complex <double> );

int main() {

    cout << "NOTE!!\n\nYou must enter the complex number on the format of (a + bi)" << endl;
    separateLine();
    cout << "If the imaginary part is 1, You must type it like --> (a + 1i)" << endl;
    separateLine();
    char op;
    string num1, num2;
    cout << "Enter 0 to exit." << endl;
    separateLine();
    cout << "Enter the first complex number, please: ";
    cin >> num1;
    if(num1 == "0")
        return 0;

    // Looping till user enter a valid complex number. 
    while(!isValidCompelxNumber(num1)){
        separateLine();
        cout << "Invalid complex number.\n" << endl;
        separateLine();
        cout << "Enter the first complex number, please: ";
        cin >> num1;
    }

    separateLine();
    cout << "Enter the second complex number, please: ";
    cin >> num2;

    // Looping till user enter a valid complex number.
    while(!isValidCompelxNumber(num2)){
        separateLine();
        cout << "Invalid complex number.\n" << endl;
        separateLine();
        cout << "Enter the second complex number, please: ";
        cin >> num2;
    }

    separateLine();
    cout << "Enter the operator, please --> (* or / or - or +):";
    cin >> op;

    // Looping till user enter a valid opreator. 
    while(isValidOperator(op)){
        separateLine();
        cout << "Invalid opertor.\n" << endl;
        separateLine();
        cout << "Enter the operator, please --> (* or / or - or +):";
        cin >> op;
    }
    separateLine();
    double firstReal, firstImg, secondReal, secondImg;

    // parsing the compex numbers to perform operations on them.
    parse_complex(num1, firstReal, firstImg);
    parse_complex(num2, secondReal, secondImg);

    // Initializing the complex numbers 
    complex <double> firstComplex(firstReal, firstImg);
    complex <double> secondComplex(secondReal, secondImg);
    complex <double> result(0, 0);

    // Performing the desired operation on the complex numbers.
    calc(op, firstComplex, secondComplex, result);

return 0;
}

bool isValidOperator(char op){
    return op != '*' && op != '-' && op != '+' && op != '/';        
}

bool isValidCompelxNumber (string& str){
    regex validComplex("[(][-+]*+[0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)]");       
    return regex_match(str, validComplex);
}

void parse_complex(string str, double& real, double& img){
    int pos = str.find_last_of('+');
    if(pos == -1){
        pos = str.find_last_of('-');
    }
    string realStr = str.substr(1, pos - 1);
    real = stod(realStr);
    int lenImgStr = str.size() - realStr.size()- 2 - 1;
    string imgStr = str.substr(pos, lenImgStr);
    img = stod(imgStr);
}

void calc(char op, complex <double> firstComplex, complex <double> secondComplex, complex <double> result){
    if(op == '+')
        result = firstComplex + secondComplex;
    else if (op == '-')
        result = firstComplex - secondComplex;
    else if (op == '*')
        result = firstComplex * secondComplex;
    else
        result = firstComplex / secondComplex;
    cout << "Result: "<< '(' << real(result) <<' ';
    cout <<  showpos << imag(result) << 'i' << ')' << endl;
    cout << "\n";
}