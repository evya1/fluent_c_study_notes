#include <stdio.h>

// Define a struct to hold person details
struct Person
{
    const char *name;
    int age;
    float height;
    float weight;
};

// Function prototype without aggregate instance
void printPersonDetailsWithoutAggregate(const char *name, int age, float height, float weight);

// Function prototype with aggregate instance
void printPersonDetailsWithAggregate(struct Person p);

// Function definition without aggregate instance
void printPersonDetailsWithoutAggregate(const char *name, int age, float height, float weight)
{
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Weight: %.2f\n", weight);
}

// Function definition with aggregate instance
void printPersonDetailsWithAggregate(struct Person p)
{
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f\n", p.height);
    printf("Weight: %.2f\n", p.weight);
}

int main()
{
    // Data for the examples
    const char *name = "Alice";
    int age = 30;
    float height = 5.5;
    float weight = 140.0;

    // Example without aggregate instance
    printf("Without Aggregate Instance:\n");
    printPersonDetailsWithoutAggregate(name, age, height, weight);

    // Create an instance of the struct and initialize it
    struct Person alice = {"Alice", 30, 5.5, 140.0};

    // Example with aggregate instance
    printf("\nWith Aggregate Instance:\n");
    printPersonDetailsWithAggregate(alice);

    // Refer to the explanation in the README.md file for more details
    // For the complete explanation, refer to the aggregate_instance.md file in the doc directory

    return 0;
}
