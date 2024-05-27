#include <stdio.h>
#include "assertion_example.h"
#include "aggregate_instance.h"

void someFunction()
{
    if ((r1 = allocateResource1()) && (r2 = allocateResource2()))
    {
        mainFunctionality();
    }
    if (r1)
    {
        cleanupResource1();
    }
    if (r2)
    {
        cleanupResource2();
    }
}

int main()
{
    // Call the main function from assertion_example.c
    assertion_example_main();

    // Call the main function from aggregate_instance.c
    aggregate_instance_main();

    return 0;
}
