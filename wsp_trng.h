#ifndef WSP_TRNG_H
#define WSP_TRNG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint64_t wsp_trng_64_randomize(void);

uint32_t wsp_trng_32_randomize(void);

uint16_t wsp_trng_16_randomize(void);

uint8_t wsp_trng_8_randomize(void);

#endif
