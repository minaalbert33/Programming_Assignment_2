#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <complex>
using namespace std;

//  check if the operator is valid or not.
bool valid_operator(char op){
    return op != '*' && op != '-' && op != '+' && op != '/';        
}

//  check if the complex number is valid or not. 
bool valid_compelx_number (string& str){
    regex valid_complex("[(][-+]*+[0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)]");       
    return regex_match(str, valid_complex);
}

//  getting the real && imaginary part of the complex number.
void parse_complex(string str, double& real, double& img){
    int pos = str.find_last_of('+');
    if(pos == -1){
        pos = str.find_last_of('-');
    }
    string real_str = str.substr(1, pos - 1);
    real = stod(real_str);
    int len_img_str = str.size() - real_str.size()- 2 - 1;
    string img_str = str.substr(pos, len_img_str);
    img = stod(img_str);
}

// Perform operations on the complex numbers.
void calc(char op, complex <double> f_complex, complex <double> s_complex, complex <double> result){
    if(op == '+')
        result = f_complex + s_complex;
    else if (op == '-')
        result = f_complex - s_complex;
    else if (op == '*')
        result = f_complex * s_complex;
    else
        result = f_complex / s_complex;
    cout << "Result: "<< '(' << real(result) <<' ';
    cout <<  showpos << imag(result) << 'i' << ')' << endl;
}

int main() {
    while(true){
        char op;
        string num1, num2;
        cout << "Enter 0 to exit." << endl;
        cout << "Enter the first complex number, please: ";
        cin >> num1;
        if(num1 == "0")
            break;
        cout << "Enter the second complex number, please: ";
        cin >> num2;
        cout << "Enter the operator, please --> (* or / or - or +):";
        cin >> op;
        if(!valid_compelx_number(num1) || !valid_compelx_number(num2) || valid_operator(op)){
            cout << "Not valid format, please try again" << endl;
            continue;
        }
        double f_real, f_img, s_real, s_img; 
        parse_complex(num1, f_real, f_img);
        parse_complex(num2, s_real, s_img);
        complex <double> f_complex(f_real, f_img);
        complex <double> s_complex(s_real, s_img);
        complex <double> result(0, 0);
        calc(op, f_complex, s_complex, result);
    }
    return 0;
}