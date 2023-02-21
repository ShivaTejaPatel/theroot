#include<stdio.h>
int main(){
  char ch=10;
  void *ptr=&ch;
  printf("%d %d", *(char*)ptr, ++(*(char*)ptr));
  return 0;
}
