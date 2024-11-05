#ifndef WSP_TRNG_H
#define WSP_TRNG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _wsp_trng_handle_error(void);

uint64_t _wsp_trng_64_oscillate(uint64_t entropy, uint64_t oscillation);

uint64_t _wsp_trng_64_capture(uint64_t entropy, uint64_t *oscillation);

uint64_t wsp_trng_64_randomize(void);

uint32_t _wsp_trng_32_oscillate(uint32_t entropy, uint32_t oscillation);

uint32_t _wsp_trng_32_capture(uint32_t entropy, uint32_t *oscillation);

uint32_t wsp_trng_32_randomize(void);

uint16_t _wsp_trng_16_oscillate(uint16_t entropy, uint16_t oscillation);

uint16_t _wsp_trng_16_capture(uint16_t entropy, uint16_t *oscillation);

uint16_t wsp_trng_16_randomize(void);

uint8_t _wsp_trng_8_oscillate(uint8_t entropy, uint8_t oscillation);

uint8_t _wsp_trng_8_capture(uint8_t entropy, uint8_t *oscillation);

uint8_t wsp_trng_8_randomize(void);

#endif
