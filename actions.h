#pragma once
#include "actions/action.h"
#include "actions/print.h"
#include "actions/match.h"
#include "actions/first_occur.h"
#include "actions/distance.h"

const std::vector<Action> Actions{
    act_print,
    act_match,
    //act_first_occur,
    act_distance
};