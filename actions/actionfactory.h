#pragma once
#include "action.h"
#include "print.h"

class ActionFactory{
    public:
        static Action* getAction(std::string identifier){
            if (identifier == "NonMatch") return new Print();
            else if (identifier == "SearchFor") return new Print();
            else{
                throw std::invalid_argument(identifier + " Is not a valid Action Identifier");
                return nullptr;
            }
        }
};