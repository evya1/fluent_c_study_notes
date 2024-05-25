# Guard Clause in C Programming

## Overview

Guard Clause is a programming technique used to improve the readability and maintainability of code by checking for pre-conditions early in a function and returning immediately if any condition is not met.

## Problem

When a function has multiple pre-conditions that need to be checked, it can lead to nested if statements and make the code harder to read and maintain. This often occurs when handling resource allocation and requires cleanup.

## Solution

Guard Clause simplifies code structure by checking pre-conditions at the beginning of a function and returning early if any condition fails. This approach helps in separating pre-condition checks from the main program logic.

### Key Steps:

1. **Identify Pre-Conditions**: Determine the mandatory pre-conditions for the function, such as valid input parameters or program state requirements.

2. **Early Return**: Check pre-conditions at the beginning of the function and return immediately if any condition is not met.

3. **Separate Functionality**: Consider moving pre-condition checks to a separate function if there are many conditions or complex checks.

4. **Resource Cleanup**: Ensure that no resource allocation occurs before pre-condition checks to simplify cleanup if conditions fail.

5. **Document Pre-Conditions**: Clearly document the pre-conditions for the function in its interface, usually in the function's header file.

## Example

### Before Guard Clause

```c
int parseFile(char* file_name) {
    int return_value = ERROR;
    FILE* file_pointer = 0;
    char* buffer = 0;

    if(file_name != NULL)
    {
        if(file_pointer = fopen(file_name, "r") != NULL)
        {
            if(buffer = malloc(BUFFER_SIZE) != NULL)
            {
                return_value = searchFileForKeywords(buffer, file_pointer);
                free(buffer);
            }
            fclose(file_pointer);
        }
    }

    return return_value;
}
```

### After Applying Guard Clause

```c
int parseFile(char* file_name) {
    int return_value = ERROR;
    FILE* file_pointer = 0;
    char* buffer = 0;

    if(file_name == NULL) return ERROR;


    if(file_pointer = fopen(file_name, "r"))
    {
        if(buffer = malloc(BUFFER_SIZE))
        {
            return_value = searchFileForKeywords(buffer, file_pointer);
            free(buffer);
        }
        fclose(file_pointer);
    }

    return return_value;
}


```

In the revised code, pre-conditions are checked at the beginning of the function using Guard Clauses, resulting in cleaner and more readable code.
