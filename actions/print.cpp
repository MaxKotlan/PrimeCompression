#include "print.h"

const Action act_print{
    .id=7861867,
    .action=[](SearchState& ss){
        std::cout << ss.gx << std::endl;
    }
};