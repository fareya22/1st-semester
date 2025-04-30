#include <iostream>
#include <string>
#include <algorithm>

class SyntaxIdentifier {
public:
    bool isExpression(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        return (statement[0] != '/' && statement[1] != '/' && statement[statement.length()-1] == ';');
    }

    bool isIf(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(statement.length() >= 3){
            if(statement[0] == 'i' && statement[1] == 'f' && statement[2] == '('){
                return true;
            }
        }
        return false;
    }

    bool isElseIf(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(statement.length() >= 7){
            if(statement[0] == 'e' && statement[1] == 'l' && statement[2] == 's'
                && statement[3] == 'e' && statement[4] == 'i' && statement[5] == 'f'
                && statement[6] == '('){
                return true;
            }
        }
        return false;
    }

    bool isElse(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(statement.length() >= 4){
            if(statement[0] == 'e' && statement[1] == 'l' && statement[2] == 's'
                && statement[3] == 'e'){
                return true;
            }
        }
        return false;
    }

    bool isWhile(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(statement.length() >= 6){
            if(statement[0] == 'w' && statement[1] == 'h' && statement[2] == 'i'
                && statement[3] == 'l' && statement[4] == 'e' && statement[5] == '('){
                return true;
            }
        }
        return false;
    }

    bool isFor(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(statement.length() >= 4){
            if(statement[0] == 'f' && statement[1] == 'o' && statement[2] == 'r' && statement[3] == '('){
                return true;
            }
        }
        return false;
    }

    bool isLoop(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        if(isFor(statement) || isWhile(statement)){
            return true;
        }
        return false;
    }

    bool foundEnd(std::string statement){
        statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
        return statement[statement.length()-1] == '}';
    }
};

