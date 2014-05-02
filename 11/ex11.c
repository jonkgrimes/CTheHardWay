#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;

  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }

  char *states[] = {
    "Texas", "California",
    "Washington", "Texas"
  };

  int num_states = 4;
  i = 0; // watch for this
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return 0;
}
