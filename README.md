# WSP-TRNG
© 2024 William Stafford Parsons

## About
WSP-TRNG is a truly-random integer generator with a temporal precision theory that guarantees randomness captured internally from quantum-level entropy as an alternative to statistical analysis guarantees.

Read more [here](https://williamstaffordparsons.github.io/wsp-trng/).

## Example
``` c
#include <stdio.h>
#include "wsp_trng.h"

int main(void) {
  unsigned char i = 0;

  while (i != 10) {
    i++;
    printf("8-bit result %u is %u.\n", i, wsp_trng_8_randomize());
  }

  i = 0;

  while (i != 10) {
    i++;
    printf("16-bit result %u is %u.\n", i, wsp_trng_16_randomize());
  }

  i = 0;

  while (i != 10) {
    i++;
    printf("32-bit result %u is %u.\n", i, wsp_trng_32_randomize());
  }

  i = 0;

  while (i != 10) {
    i++;
    printf("64-bit result %u is %u.\n", i, wsp_trng_64_randomize());
  }

  return 0;
}
```
