# Goto Error Handling in C

## Overview

In programming, particularly in C, managing error conditions and resource cleanup within functions can become complex. This complexity often arises when a function is responsible for acquiring and releasing multiple resources. Despite attempts to simplify the code using various techniques like Guard Clause or Function Split, a nested if construct may still persist due to resource acquisition, leading to duplicated cleanup code.

## Table of Contents

1. [Overview](#overview)
2. [Problem](#problem)
3. [Solution](#solution)
4. [Goto: Good or Evil?](#goto-good-or-evil)
5. [Consequences](#consequences)
6. [Known Uses](#known-uses)
7. [General structure](#general-structure)
8. [Before](#before)
9. [After](#after)

## Problem

The challenge arises when functions need to acquire and release multiple resources at different points within the code. Each resource acquisition can potentially fail, necessitating error handling. However, handling these errors within the function's flow can lead to nested if statements, making the code difficult to read and maintain. Additionally, returning in the middle of the function when an error occurs isn't optimal, as it requires cleaning up all previously acquired resources before each return statement.

## Solution

One solution to this problem is to consolidate all resource cleanup and error handling at the end of the function. This approach streamlines the code and makes it more readable. Using the `goto` statement allows jumping to the resource cleanup code when a resource cannot be acquired. Resources should be acquired in the required order, and cleanup should be performed in reverse order. Each cleanup operation should have a separate label to which the function can jump if needed.

## Goto: Good or Evil?

The debate around the usage of goto statements in programming, particularly in C, has been ongoing for years. While some argue that goto statements can lead to code that is difficult to understand and maintain, others defend their use in certain situations, such as error handling and resource cleanup. Understanding when and how to use goto statements effectively is crucial in maintaining code readability and manageability.

## Consequences

Implementing goto error handling in C functions offers both advantages and considerations. On one hand, it simplifies the code by eliminating nested if statements and consolidating error handling and resource cleanup. However, not everyone is accustomed to reading code with goto statements, and misuse of goto can lead to code that is difficult to maintain. Careful consideration of when to use goto and ensuring proper labeling of cleanup points are essential to mitigate potential pitfalls.

## Known Uses

Various software projects and coding standards advocate for the use of goto statements in certain contexts. Examples include the Linux kernel codebase, the CERT C Coding Standard, and libraries like OpenSSL. While goto statements are sometimes frowned upon, they can offer a pragmatic solution to complex error handling scenarios, particularly in low-level systems programming. Understanding the context and guidelines for goto usage in specific projects is key to leveraging its benefits effectively.

## General structure

```c
void someFunction() {
    if (!allocateResource1()) {
        goto cleanup1;
    }
    if (!allocateResource2()) {
        goto cleanup2;
    }
    mainFunctionality();
  cleanup2:
    cleanupResource2();
  cleanup1:
    cleanupResource1();
}
```

## Before

```c
int parseFile(char* file_name) {
    int return_value = ERROR;
    FILE* file_pointer = 0;
    char* buffer = 0;
    assert(file_name != NULL && "Invalid filename");

    if (file_pointer = fopen(file_name, "r")) {
        if (buffer = malloc(BUFFER_SIZE)) {
            return_value = searchFileForKeywords(buffer, file_pointer);
            free(buffer);
        }
        fclose(file_pointer);
    }
    return return_value;
}
```

## After

```c
int parseFile(char* file_name) {
    int return_value = ERROR;
    FILE* file_pointer = 0;
    char* buffer = 0;
    assert(file_name != NULL && "Invalid filename");

    if (!(file_pointer = fopen(file_name, "r"))) {
        goto error_fileopen;
    }
    if (!(buffer = malloc(BUFFER_SIZE))) {
        goto error_malloc;
    }
    return_value = searchFileForKeywords(buffer, file_pointer);
    free(buffer);

    error_malloc:
        fclose(file_pointer);
    error_fileopen:
        return return_value;
}
```
