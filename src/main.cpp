#include <string>
#include <iostream>
#include <set>
using namespace std;
int main(){
    /*
    1. keyboard (input)
    2. plugboard swap (0/1 changes)
    3. left rotor, middle rotor, right rotor (3 changes)
    4. reflector (1 change)
    5. right rotor, middle rotor, left rotor (3 changes)
    6. plugboard (0/1 changes)
    7. keyswitch?
    8. light blub (output)
    */
    string phraseToEncrypt;
    string rotorPos;
    int leftRotorStartNum;
    int middleRotorStartNum;
    int rightRotorStartNum;
    string switchboardPairs;
    // getting phrase
    cout << "What phrase would you like to encrypt? :: " << endl;
    cin >> phraseToEncrypt;

    //getting rotor positions
    cout << "What rotor positions would you like to use? (eg. 123) would be rotor 1 at left position, rotor 2 at right position, rotor 3 at right position. :: " << endl;
    cin >> rotorPos;

    //getting rotor starting numbers, idc abt input validation since they wont be a problem once its in blender
    cout << "What number will the left rotor start at? (1-26) :: "<< endl;
    cin >> leftRotorStartNum;
    cout << "What number will the middle rotor start at? (1-26) :: "<< endl;
    cin >> middleRotorStartNum;
    cout << "What number will the right rotor start at? (1-26) :: "<< endl;
    cin >> rightRotorStartNum;

    //getting switchboard pairs
    string input;
    while (true){
        cout << "Add a pair of letters to be swapped (AB to switch A and B, 'n' to stop)"<< endl;
        cin >> input;
        if (input=="n"){
            break;
        }
        string temp = switchboardPairs + input + " ";
        bool isDupe = false;
        bool onlyChar = true;
        set<char> charSet;
        // validating that there are no duplicates in switchboard (one letter can only be swapped once) and there are only uppercase characters of length 2
        for (char ch : temp) {
            if (!(isupper(ch) || ch==' ')){
                onlyChar = false;
            }
            if (charSet.find(ch) != charSet.end()) {
                isDupe = true; 
            }
            if (ch!=' '){
                charSet.insert(ch);
            }
        }
        
        if (isDupe || input.length()!=2 || !onlyChar){
            cout << "Invalid pair!"<< endl;
        }
        else{
            switchboardPairs=temp;
        }
    }
    switchboardPairs=switchboardPairs.substr(0,switchboardPairs.length()-1); //removing trailing space
    
    cout << "Starting encryption of phrase '" << phraseToEncrypt << "'" << endl;
    cout << "Rotor postions at " << rotorPos << "." << endl;
    cout << "Rotor start numbers at " << leftRotorStartNum << ", " << middleRotorStartNum << ", " << rightRotorStartNum << "." << endl;
    cout << "Switchboard swaps :: '" << switchboardPairs << "'." << endl;
}