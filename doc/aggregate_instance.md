# Aggregate Instance Pattern in C

## Overview

In C programming, an _aggregate instance_ typically refers to a variable of a struct or array type. Aggregates allow you to group multiple related variables together, which can then be passed as a single entity to a function. This approach simplifies function signatures and helps avoid errors associated with passing multiple parameters.

## Table of Contents

1. [Overview](#aggregate-instance-pattern-in-c)
2. [Explanation](#explanation)
3. [Example with Code Snippets](#example-with-code-snippets)
    - [Without Aggregate Instance](#without-aggregate-instance)
    - [With Aggregate Instance](#with-aggregate-instance)
4. [Visualization](#visualization)
    - [Without Aggregate Instance](#without-aggregate-instance-1)
    - [With Aggregate Instance](#with-aggregate-instance-1)
5. [File References](#file-references)

## Explanation

When a function requires several parameters, you can group these parameters into a _struct_, which is a composite data type that contains different variables, possibly of different types. By passing a single struct instance to the function, you reduce the number of parameters and make your code more readable and less error-prone.

### Example with Code Snippets

#### Without Aggregate Instance

Consider a scenario where you need to pass multiple parameters to a function:

```c
#include <stdio.h>

void printPersonDetails(const char *name, int age, float height, float weight) {
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Weight: %.2f\n", weight);
}

int main() {
    const char *name = "Alice";
    int age = 30;
    float height = 5.5;
    float weight = 140.0;

    printPersonDetails(name, age, height, weight);

    return 0;
}
```

This function signature is prone to errors, especially if you accidentally switch the order of the parameters.

#### With Aggregate Instance

To make the code cleaner, you can define a struct to hold all the related information:

```c
#include <stdio.h>

// Define a struct to hold person details
struct Person {
    const char *name;
    int age;
    float height;
    float weight;
};

// Function that takes a struct instance
void printPersonDetails(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f\n", p.height);
    printf("Weight: %.2f\n", p.weight);
}

int main() {
    // Create an instance of the struct and initialize it
    struct Person alice = {"Alice", 30, 5.5, 140.0};

    // Pass the struct instance to the function
    printPersonDetails(alice);

    return 0;
}
```

In this example, the `Person` struct aggregates all the parameters into a single variable. The function `printPersonDetails` now takes a single parameter of type `struct Person`. This makes the function call more straightforward and reduces the risk of parameter order errors.

## Visualization

### Without Aggregate Instance

Multiple parameters are passed individually.

```
+--------+   +-----+   +--------+   +--------+
|  name  |   | age |   | height |   | weight |
+--------+   +-----+   +--------+   +--------+
```

### With Aggregate Instance

A single struct instance encapsulates all parameters.

```
+-----------------------------+
|          Person             |
| +--------+   +-----+        |
| |  name  |   | age |        |
| +--------+   +-----+        |
| +--------+   +--------+     |
| | height |   | weight |     |
| +--------+   +--------+     |
+-----------------------------+
```

By using an aggregate instance, you improve the maintainability and readability of your code, making it easier to understand and less error-prone.

## File References

-   [aggregate_instance.c](../src/aggregate/aggregate_instance.c)
-   [aggregate_instance.h](../src/aggregate/aggregate_instance.h)
