#ifdef MAIN

#include "ABDQ.hpp"
#include "ABQ.hpp"
#include "ABS.hpp"
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include "LLDQ.hpp"
#include "LLQ.hpp"
#include "LLS.hpp"
#include <iostream>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.
*/

int main() {
    ABS<int> test;
    test.push(1);
    test.push(2);
    std::cout << test.getMaxCapacity();
    test.push(3);
    test.push(4);
    std::cout << test.getMaxCapacity();
    test.pop();
    test.pop();
    test.pop();
    std::cout << test.getMaxCapacity();
    ABS<int> test2 = std::move(test);


    auto& debugTest = test2;
    std::cout << "\ndebugginggg --- \n";
    while (debugTest.getSize() != 0 )
    {
        std::cout << debugTest.pop() << "  ";
    }

    return 0;
}


#endif