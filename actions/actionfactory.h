#pragma once
#include "action.h"
#include "print.h"
#include "match.h"
#include "first_occur.h"
#include "distance.h"


class ActionFactory{
    public:
        static Action* getAction(std::string identifier){
            if (identifier == "NonMatch") return new Print();
            else if (identifier == "SearchFor") return new Match();
            else if (identifier == "FirstOccur") return new FirstOccur();
            else if (identifier == "Distance") return new Distance();
            else{
                throw std::invalid_argument(identifier + " Is not a valid Action Identifier");
                return nullptr;
            }
        }
};