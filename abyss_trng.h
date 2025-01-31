#ifndef ABYSS_TRNG_H
#define ABYSS_TRNG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint64_t abyss_trng_64_randomize(void);

uint32_t abyss_trng_32_randomize(void);

uint16_t abyss_trng_16_randomize(void);

uint8_t abyss_trng_8_randomize(void);

#endif
