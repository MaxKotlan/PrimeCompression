#pragma once
#include "action.h"
#include "print.h"
#include "match.h"
#include "first_occur.h"
#include "distance.h"


class ActionFactory{
    public:
        static std::shared_ptr<Action> getAction(std::string identifier){
            if (identifier == "NonMatch")        return std::shared_ptr<Action>(new Print());
            else if (identifier == "SearchFor")  return std::shared_ptr<Action>(new Match());
            else if (identifier == "FirstOccur") return std::shared_ptr<Action>(new FirstOccur());
            else if (identifier == "Distance")   return std::shared_ptr<Action>(new Distance());
            else{
                throw std::invalid_argument(identifier + " Is not a valid Action Identifier");
                return nullptr;
            }
        }
};