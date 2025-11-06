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
    // ABDQ<int> test;
    // test.pushBack(1);
    // test.pushBack(2);
    // // test.printData();
    // std::cout << test.getMaxCapacity();
    // test.pushBack(3);
    // test.pushBack(4);
    // // test.printData();
    // std::cout << test.getMaxCapacity();
    // test.popFront();
    // test.popFront();
    // // test.pop();
    // std::cout << test.getMaxCapacity();
    // ABDQ<int> test2 = std::move(test);
    // test.printData();

    LLDQ<int> test;
    test.pushBack(1);
    test.pushBack(2);
    test.pushBack(3);
    test.pushBack(4);
    test.popFront();
    auto test2(std::move(test));
    test2.pushFront(5);
    std::cout << test2.front() << "\n";


    auto& debugTest = test2;
    std::cout << "\ndebugginggg --- \n";
    while (debugTest.getSize() != 0 )
    {
        std::cout << debugTest.popFront() << "  ";
        // test.printData();
    }

    // std::cout << debugTest.front();

    return 0;
}


#endif