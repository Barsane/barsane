//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_EXPECT_H
#define BARZANE_EXPECT_H


#include <iostream>

#define DESCRIPTION_COLOR "\033[0;36m"

#define FAILED_COLOR "\033[0;31m"

#define SUCCESS_COLOR "\033[0;32m"

#define RESET_COLOR "\033[0m"

inline unsigned int __failed_counter() {static unsigned int failed_count = 0; return ++failed_count; }

inline unsigned int __success_counter() {static unsigned int success_count = 0; ++success_count; }

#define expect(description, expression)                                                     \
     if (!static_cast<bool>(expression)) {                                                  \
         std::cout << DESCRIPTION_COLOR << static_cast<std::string>(description)            \
                   << RESET_COLOR << std::endl                                              \
                   << "\t" << FAILED_COLOR << __FILE__ << ":" << __LINE__ <<": "            \
                   << __PRETTY_FUNCTION__  << ": Assertion `"<< #expression                 \
                   <<"` failed " << RESET_COLOR << std::endl;                               \
         __failed_counter();                                                                \
    } else {                                                                                \
        __success_counter();                                                                \
    }

#define print_rst() {                                                                       \
        unsigned int failed = __failed_counter();                                           \
        unsigned int success = __success_counter();                                         \
        std::cout << std::endl << FAILED_COLOR << "Failed: " << --failed << "\t"            \
                  << SUCCESS_COLOR << "Success: " << --success << RESET_COLOR << std::endl; \
    }

#endif //BARZANE_EXPECT_H
