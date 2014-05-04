#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) 
{
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person *jon = Person_create("Jon Grimes",31,73,198);

  struct Person *ken = Person_create("Ken Seals", 29, 72, 180);

  // print them out and where they are in memory
  printf("Jon is at memory location %p:\n", jon);
  Person_print(jon);

  printf("Ken is at memory locaiton %p:\n", ken);
  Person_print(ken);

  // age everyone 20 years
  jon->age += 20;
  jon->height -= 2;
  jon->weight += 40;
  Person_print(jon);

  ken->age += 20;
  ken->weight += 20;
  Person_print(ken);

  // destroy them both
  // Person_destroy(jon);
  // Person_destroy(ken);

  return 0;
}
