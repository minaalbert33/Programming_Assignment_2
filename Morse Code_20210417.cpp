#include <iostream>
#include <string>
using namespace std;
string charToMorse(char);
string morseToChar(string);

int main(){
    while(true){
        int user_choice;
        string input;
        string output = "";
        int node = 0;
        string sub;
        cout << "1)--> Cipher\n2)--> Decipher\n3)-->Exit " << endl;
        cin >> user_choice;
        if(user_choice == 1){
            getline(cin >> ws, input);
            for(int i = 0; i < input.length(); i++){
                if(i>=0){
                    output +=  charToMorse(input[i]);
                }
                output+=" ";
            }
            cout << ' ';
        }else if (user_choice == 2){
            getline(cin >> ws, input);
            for(int i = 0; i <= input.length(); i++){
                if(input[i]==' '){
                    sub = input.substr(node,i-node);
                    output+=morseToChar(sub);
                    node = i+1;
                }
                if(i==input.length()-1){
                    sub = input.substr(node,i+1-node);
                    output+=morseToChar(sub);
                    node = i+1;
                }
            }
        }else{
            return 0 ;
        }
        cout << "Morse Text: " << output << endl;

        break;
    }
}

string morseToChar(string morsecode){
        if(morsecode == ".-")
        {return "a";}
        else if(morsecode == "-...")
        {return "b";}
        else if(morsecode == "-.-.")
        {return "c";}
        else if(morsecode == "-..")
        {return "d";}
        else if(morsecode == ".")
        {return "e";}
        else if(morsecode == "..-.")
        {return "f";}
        else if(morsecode == "--.")
        {return "g";}
        else if(morsecode == "....")
        {return "h";}
        else if(morsecode == "..")
        {return "i";}
        else if(morsecode == ".---")
        {return "j";}
        else if(morsecode == "-.-")
        {return "k";}
        else if(morsecode == ".-..")
        {return "l";}
        else if(morsecode == "--")
        {return "m";}
        else if(morsecode == "-.")
        {return "n";}
        else if(morsecode == "---")
        {return "o";}
        else if(morsecode == ".--.")
        {return "p";}
        else if(morsecode == "--.-")
        {return "q";}
        else if(morsecode == ".-.")
        {return "r";}
        else if(morsecode == "...")
        {return "s";}
        else if(morsecode == "-")
        {return "t";}
        else if(morsecode == "..-")
        {return "u";}
        else if(morsecode == "...-")
        {return "v";}
        else if(morsecode == ".--")
        {return "w";}
        else if(morsecode == "-..-")
        {return "x";}
        else if(morsecode == "-.--")
        {return "y";}
        else if(morsecode == "--..")
        {return "z";}
        else{return " ";}
}

string charToMorse(char letter){
    switch(tolower(letter)){
        case 'a':
        return ".-"; break;
        case 'b':
        return "-..."; break;
        case 'c':
        return "-.-."; break;
        case 'd':
        return "-.."; break;
        case 'e':
        return "."; break;
        case 'f':
        return "..-."; break;
        case 'g':
        return "--."; break;
        case 'h':
        return "...."; break;
        case 'i': 
        return ".."; break;
        case 'j': 
        return ".---"; break;
        case 'k': 
        return "-.-"; break;
        case 'l': 
        return ".-.."; break;
        case 'm': 
        return "--"; break;
        case 'n':
        return "-."; break;
        case 'o':
        return "---"; break;
        case 'p':
        return ".--."; break;
        case 'q':
        return "--.-"; break;
        case 'r':
        return ".-."; break;
        case 's': 
        return "..."; break;
        case 't':
        return "-"; break;
        case 'u': 
        return "..-"; break;
        case 'v':
        return "...-"; break;
        case 'w': 
        return ".--"; break;
        case 'x':
        return "-..-"; break;
        case 'y':
        return "-.--"; break;
        case 'z':
        return "--.."; break;
        default:
        return " "; break;
    }
}