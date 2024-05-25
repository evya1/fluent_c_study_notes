#ifndef AGGREGATE_INSTANCE_H
#define AGGREGATE_INSTANCE_H

struct Person
{
    const char *name;
    int age;
    float height;
    float weight;
};

void printPersonDetailsWithoutAggregate(const char *name, int age, float height, float weight);
void printPersonDetailsWithAggregate(struct Person p);
void aggregate_instance_main();

#endif /* AGGREGATE_INSTANCE_H */
