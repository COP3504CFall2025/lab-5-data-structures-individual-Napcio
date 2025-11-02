#ifdef MAIN

#include "ABDQ.hpp"
// #include "ABQ.hpp"
// #include "ABS.hpp"
#include "Interfaces.hpp"
// #include "LinkedList.hpp"
// #include "LLDQ.hpp"
// #include "LLQ.hpp"
// #include "LLS.hpp"
#include <iostream>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.

*/

int main() {
    ABDQ<int> test;
    test.pushBack(2);
    test.pushBack(3);
    test.pushBack(4);
    test.pushFront(1);
    test.pushBack(5);
    test.pushFront(0);
    test.printData();

    ABDQ test2 = std::move(test);
    test.printData();
    test2.printData();

    // std::cout << test.popBack();
    // test.pushBack(3);

    std::cout << "\ndebugginggg --- \n";
    while (test2.getSize() != 0 )
    {
        std::cout << test2.popFront() << "  ";
    }

    return 0;
}


#endif