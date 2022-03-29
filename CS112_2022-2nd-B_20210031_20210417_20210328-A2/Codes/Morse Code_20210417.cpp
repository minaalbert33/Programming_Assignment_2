/* Author : Mina Albert Saeed
 * Course : CS 112
 * Instructor: Dr. Mohammad El-Ramly
 * Assignment : Assignment 2 – Version 5.0
 *
 * */

#include <iostream>
#include <string>
using namespace std;
string charToMorse(char);
string morseToChar(string);

int main(){
    while(true){
        int userChoice;
        string input;
        string output = "";
        int node = 0;
        string sub;
        cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?" << endl;
        cout << "1)--> Cipher\n2)--> Decipher\n3)-->Exit " << endl;
        cin >> userChoice;
        if(userChoice == 1){
            cout << "Enter a message to cipher: ";
            getline(cin >> ws, input);
            for(int i = 0; i < input.length(); i++){
                    output +=  charToMorse(input[i]);
                output+=" ";
            }
            cout << ' ';
        }else if (userChoice == 2){
            
            cout << "Enter a message to decipher: ";
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

string morseToChar(string morseCode){
        if(morseCode == ".-")
        {return "a";}
        else if(morseCode == "-...")
        {return "b";}
        else if(morseCode == "-.-.")
        {return "c";}
        else if(morseCode == "-..")
        {return "d";}
        else if(morseCode == ".")
        {return "e";}
        else if(morseCode == "..-.")
        {return "f";}
        else if(morseCode == "--.")
        {return "g";}
        else if(morseCode == "....")
        {return "h";}
        else if(morseCode == "..")
        {return "i";}
        else if(morseCode == ".---")
        {return "j";}
        else if(morseCode == "-.-")
        {return "k";}
        else if(morseCode == ".-..")
        {return "l";}
        else if(morseCode == "--")
        {return "m";}
        else if(morseCode == "-.")
        {return "n";}
        else if(morseCode == "---")
        {return "o";}
        else if(morseCode == ".--.")
        {return "p";}
        else if(morseCode == "--.-")
        {return "q";}
        else if(morseCode == ".-.")
        {return "r";}
        else if(morseCode == "...")
        {return "s";}
        else if(morseCode == "-")
        {return "t";}
        else if(morseCode == "..-")
        {return "u";}
        else if(morseCode == "...-")
        {return "v";}
        else if(morseCode == ".--")
        {return "w";}
        else if(morseCode == "-..-")
        {return "x";}
        else if(morseCode == "-.--")
        {return "y";}
        else if(morseCode == "--..")
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
