#pragma once
#include <map>
#include <string>
class Plugboard{
        private:
                std::map<char, char> connections;
        public:
                Plugboard();
                Plugboard(std::string initString);
                char process(char c);
                std::string toString();
};

