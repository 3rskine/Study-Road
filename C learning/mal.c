#include <stdio.h>
#include <stdlib.h>

int main() {
  int *students;
  int numStudents;
  scanf("%d" , &numStudents);
  students = calloc(numStudents, sizeof(*students));
  printf("%d", numStudents * sizeof(*students)); // 48 bytes
  
  return 0;
}