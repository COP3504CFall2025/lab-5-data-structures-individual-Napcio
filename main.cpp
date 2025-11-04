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
    LinkedList<int> test;
    test.addTail(1);
    test.addTail(2);
    test.addTail(3);
    test.addHead(0);
    test.addHead(-1);
    test.printForward();
    test.clear();
    test.printForward();
    test.addHead(0);
    test.addHead(1);
    test.addHead(2);
    test.printReverse();


    std::cout << "\ndebugginggg --- \n";
    while (test.getSize() != 0 )
    {
        std::cout << test.removeTail() << "  ";
    }

    return 0;
}


#endif