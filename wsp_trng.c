#include "wsp_trng.h"

void _wsp_trng_handle_error(void) {
  exit(EXIT_FAILURE);
}

uint64_t _wsp_trng_64_oscillate(uint64_t entropy, uint64_t oscillation) {
  oscillation *= ((entropy / 11111111) % 111) + ((entropy + oscillation) % 111);
  oscillation /= (entropy - oscillation) | 1;
  oscillation = ((entropy + oscillation) % 65535) + 11111111;
  return oscillation;
}

uint64_t _wsp_trng_64_capture(uint64_t entropy, uint64_t *oscillation) {
  struct timespec s;

  if (clock_gettime(CLOCK_REALTIME, &s) == 0) {
    *oscillation += entropy;
    entropy = (entropy << 1) | (s.tv_nsec & 1);
  } else {
    _wsp_trng_handle_error();
  }

  return entropy;
}

uint64_t wsp_trng_64_randomize(void) {
  uint64_t entropy = 1;
  uint64_t oscillation = 1111111111;

  while ((entropy >> 63) != 1) {
    oscillation = _wsp_trng_64_oscillate(entropy, oscillation);
    entropy = _wsp_trng_64_capture(entropy, &oscillation);
  }

  oscillation = _wsp_trng_64_oscillate(entropy, oscillation);
  entropy = _wsp_trng_64_capture(entropy, &oscillation);

  if (oscillation == 0) {
    oscillation = _wsp_trng_64_oscillate(entropy, oscillation);
    entropy = _wsp_trng_64_capture(entropy, &oscillation);
  }

  return entropy;
}

uint32_t _wsp_trng_32_oscillate(uint32_t entropy, uint32_t oscillation) {
  oscillation *= ((entropy / 111111) % 111) + ((entropy + oscillation) % 111);
  oscillation /= (entropy - oscillation) | 1;
  oscillation = ((entropy + oscillation) % 65535) + 111111;
  return oscillation;
}

uint32_t _wsp_trng_32_capture(uint32_t entropy, uint32_t *oscillation) {
  struct timespec s;

  if (clock_gettime(CLOCK_REALTIME, &s) == 0) {
    *oscillation += entropy;
    entropy = (entropy << 1) | (s.tv_nsec & 1);
  } else {
    _wsp_trng_handle_error();
  }

  return entropy;
}

uint32_t wsp_trng_32_randomize(void) {
  uint32_t entropy = 1;
  uint32_t oscillation = 1111111111;

  while ((entropy >> 31) != 1) {
    oscillation = _wsp_trng_32_oscillate(entropy, oscillation);
    entropy = _wsp_trng_32_capture(entropy, &oscillation);
  }

  oscillation = _wsp_trng_32_oscillate(entropy, oscillation);
  entropy = _wsp_trng_32_capture(entropy, &oscillation);

  if (oscillation == 0) {
    oscillation = _wsp_trng_32_oscillate(entropy, oscillation);
    entropy = _wsp_trng_32_capture(entropy, &oscillation);
  }

  return entropy;
}

uint16_t _wsp_trng_16_oscillate(uint16_t entropy, uint16_t oscillation) {
  oscillation *= ((entropy / 11111) % 111) + ((entropy + oscillation) % 111);
  oscillation /= (entropy - oscillation) | 1;
  oscillation = ((entropy + oscillation) % 65535) + 11111;
  return oscillation;
}

uint16_t _wsp_trng_16_capture(uint16_t entropy, uint16_t *oscillation) {
  struct timespec s;

  if (clock_gettime(CLOCK_REALTIME, &s) == 0) {
    *oscillation += entropy;
    entropy = (entropy << 1) | (s.tv_nsec & 1);
  } else {
    _wsp_trng_handle_error();
  }

  return entropy;
}

uint16_t wsp_trng_16_randomize(void) {
  uint16_t entropy = 1;
  uint16_t oscillation = 11111;

  while ((entropy >> 15) != 1) {
    oscillation = _wsp_trng_16_oscillate(entropy, oscillation);
    entropy = _wsp_trng_16_capture(entropy, &oscillation);
  }

  oscillation = _wsp_trng_16_oscillate(entropy, oscillation);
  entropy = _wsp_trng_16_capture(entropy, &oscillation);

  if (oscillation == 0) {
    oscillation = _wsp_trng_16_oscillate(entropy, oscillation);
    entropy = _wsp_trng_16_capture(entropy, &oscillation);
  }

  return entropy;
}

uint8_t _wsp_trng_8_oscillate(uint8_t entropy, uint8_t oscillation) {
  oscillation *= ((entropy / 111) % 111) + ((entropy + oscillation) % 111);
  oscillation /= (entropy - oscillation) | 1;
  oscillation = ((entropy + oscillation) % 65535) + 111;
  return oscillation;
}

uint8_t _wsp_trng_8_capture(uint8_t entropy, uint8_t *oscillation) {
  struct timespec s;

  if (clock_gettime(CLOCK_REALTIME, &s) == 0) {
    *oscillation += entropy;
    entropy = (entropy << 1) | (s.tv_nsec & 1);
  } else {
    _wsp_trng_handle_error();
  }

  return entropy;
}

uint8_t wsp_trng_8_randomize(void) {
  uint8_t entropy = 1;
  uint8_t oscillation = 111;

  while ((entropy >> 7) != 1) {
    oscillation = _wsp_trng_8_oscillate(entropy, oscillation);
    entropy = _wsp_trng_8_capture(entropy, &oscillation);
  }

  oscillation = _wsp_trng_8_oscillate(entropy, oscillation);
  entropy = _wsp_trng_8_capture(entropy, &oscillation);

  if (oscillation == 0) {
    oscillation = _wsp_trng_8_oscillate(entropy, oscillation);
    entropy = _wsp_trng_8_capture(entropy, &oscillation);
  }

  return entropy;
}
