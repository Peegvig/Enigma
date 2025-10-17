#include "/home/csce120/Enigma/header/Plugboard.h"
#include <string>
#include <sstream>
#include <iostream>
Plugboard::Plugboard(){
        for(char c = 'A'; c< 'Z';c++ ){
                Plugboard::connections.at(c) = c;
        }
}

Plugboard::Plugboard(std::string initString){
        std::stringstream s;
        s<<initString;
        std::string pair;
        while(s>>pair){
                Plugboard::connections.at(pair.at(0)) = pair.at(1);
                Plugboard::connections.at(pair.at(1)) = pair.at(0);
        }

}

char Plugboard::process(char c){
        return Plugboard::connections.at(c);
}

std::string Plugboard::toString(){
        std::string s;
        for(auto it = Plugboard::connections.begin(); it != Plugboard::connections.end();it++){
                s += std::to_string(it->first) + " is mapped to " + std::to_string(it->second);
        }
}

