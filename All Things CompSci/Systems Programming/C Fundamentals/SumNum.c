#include <stdio.h>
#include <stdint.h>

void sumstore(int32_t x, int32_t y, int32_t* dest);

int main(int argc, char** argv) {
  int32_t z, x = 351, y = 333;

  sumstore(x,y,&z);
  
  printf("%i + %i = %i\n",x,y,z);
  return 0;
}