#include <iostream>
#include "timing.hpp"

int main() {
    
    { 
        // use the timer in a scope 
        auto t = timing::msTimer("An example ms timer");
        // ......................
        // YOUR CODE GOES HERE...
        // ......................
        // the timer will print out elapsed time
    }

    // you can use the namespace to save some typing
    using namespace timing;
    {
        auto t = nsTimer("Timing in ns?");
        // you can time separate laps:
        for (int i = 0; i < 30; i++)
        {
            if (i % 10 == 0) {
                t.time("10 iterations");
            }
        }
    }
}