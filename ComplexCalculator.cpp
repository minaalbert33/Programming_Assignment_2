#include <bits/stdc++.h>
using namespace std;
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
bool valid_operator(char op){
    return op != '*' && op != '-' && op != '+' && op != '/';
}

bool valid_compelx_number (string& str){
    regex valid_complex("[(][0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)]");
    return regex_match(str, valid_complex);
}

double parse_complex(string str, int type){
    int pos = str.find('+');
    if(pos == -1){
        pos = str.find('-');
    }

    string real_str = str.substr(1, pos - 1);
    int len_img_str = str.size() - real_str.size()- 2 - 1;
    string img_str = str.substr(pos, len_img_str);
    double res;

    if (type == 1)
        res = stof(real_str);
    else if (type == 2)
        res = stof(img_str);

    return res;
}


void calc(char op, string& num1, string& num2){
    string res;
    double real_num1 = parse_complex(num1, 1);
    double img_num1 = parse_complex(num1, 2);
    double real_num2 = parse_complex(num2, 1);
    double img_num2 = parse_complex(num2, 2);


    if(op == '+'){
        if (img_num1 + img_num2 >= 0)
            res = '(' + to_string(real_num1 + real_num2) + " + " + to_string(img_num1 + img_num2) + 'i' + ')';
        else
            res = '(' + to_string(real_num1 + real_num2) + "  "+ to_string(img_num1 + img_num2) + 'i' + ')';
    }

    cout << res << endl;
}
int main() {
    while(true){
        cout << "Please Enter two numbers and operator or 0 to exit" << endl;
        char op;
        string num1, num2;
        cin >> num1 >> num2 >> op;
        if(num1 == "0")
            break;
        if(!valid_compelx_number(num1) || !valid_compelx_number(num2) || valid_operator(op)){
            cout << "Not valid format, please try again" << endl;
            continue;
        }

        if(num1[1] != '-'){
            calc(op, num1, num2);
        }
    }

    return 0;
}
