#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;

  // skip first argument
  for(i = 1;i < argc;i++) {
    printf("arg %d: %s\n",i,argv[i]);
  }

  char *states[] = {
    "California",
    "Texas",
    "Oregon",
    "Washington"
  };
  int num_states = 6;

  for(i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}
