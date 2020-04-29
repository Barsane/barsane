//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_EXPECT_H
#define BARZANE_EXPECT_H


#include <iostream>

#define DESCRIPTION_COLOR "\033[0;36m"

#define FAILED_COLOR "\033[0;31m"

#define RESET_COLOR "\033[0m"

#define expect(description, expression)                                                     \
     if (!static_cast<bool>(expression))                                                    \
         std::cout << DESCRIPTION_COLOR << static_cast<std::string>(description)            \
                   << RESET_COLOR << std::endl                                              \
                   << "\t" << FAILED_COLOR << __FILE__ << ":" << __LINE__ <<": "            \
                   << __PRETTY_FUNCTION__  << ": Assertion `"<< #expression                 \
                   <<"` failed " << RESET_COLOR << std::endl


#endif //BARZANE_EXPECT_H
