#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die */
void die(const char *message)
{
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

// creates a fake type for the function pointer
typedef int (*compare_cb)(int a, int b);
typedef int *(sorter)(int *numbers, int count, compare_cb cmp); 

void quick_sort_r(int *target, int *left, int *right);
int *partition(int *array, int *left, int *right, int *pivot);
void swap(int *left, int *right);

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;
  int *target = malloc(count *sizeof(int));

  if(!target) die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for(i = 0; i < count; i++) {
    for(j = 0; j < count - 1; j++) {
      if(cmp(target[j], target[j+1]) > 0) {
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }

  return target;
}

int *quick_sort(int *numbers, int count, compare_cb cmp)
{
  int *target = malloc(count *sizeof(int));

  if(!target) die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  // kick off the sort
  quick_sort_r(target, target, target+(count-1));

  return target;
}

void quick_sort_r(int *target, int *left, int *right)
{
  // printf("Left address: %p\n",left);
  // printf("Left: %d\n",*left);
  // printf("Right address: %p\n",right);
  // printf("Right: %d\n",*right);

  int *pivot = NULL;
  int *newPivot = NULL;

  if(left < right) {
    pivot = left + (right - left) / 2;
    newPivot = partition(target,left,right,pivot);
    quick_sort_r(target, left, newPivot - 1);
    quick_sort_r(target, newPivot + 1, right);
  }
}

int *partition(int *array, int *left, int *right, int *pivot)
{
  int pivotValue = *pivot;
  swap(pivot,right);
  int *index = left;
  for(int *i = left; i < right; i++) {
    if(*i <= pivotValue) {
      swap(i,index);
      index++;
    }
  }
  swap(index,right);

  return index;
}

void swap(int *left, int *right)
{
  int *temp = left;
  left = right;
  right = temp;
}

int sorted_order(int a, int b)
{
  return a - b;
}

int reverse_order(int a, int b)
{
  return b - a;
}

int strange_order(int a, int b)
{
  if(a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

// test to make sure things are sorting correctly
void test_sorting(int *numbers, int count, sorter sort, compare_cb cmp)
{
  int i = 0;
  int *sorted = sort(numbers, count, cmp);

  if(!sorted) die("Failed to sort as requested.");

  for(i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  free(sorted);
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if(!numbers) die("Memory error.");

  for(i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  printf("=== Testing bubble_sort ===\n");
  test_sorting(numbers, count, bubble_sort, sorted_order);
  test_sorting(numbers, count, bubble_sort, reverse_order);
  test_sorting(numbers, count, bubble_sort, strange_order);

  printf("=== Testing quick_sort ===\n");
  test_sorting(numbers, count, quick_sort, sorted_order);
  test_sorting(numbers, count, quick_sort, reverse_order);
  test_sorting(numbers, count, quick_sort, strange_order);

  free(numbers);

  return 0;
}
