#include <stdio.h>
#include "assertion_example.h"
#include "aggregate_instance.h"

int main()
{
    // Call the main function from assertion_example.c
    assertion_example_main();

    // Call the main function from aggregate_instance.c
    aggregate_instance_main();

    return 0;
}
