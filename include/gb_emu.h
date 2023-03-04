#pragma once

#include <common.h>

typedef struct
{
  bool paused;
  bool running;
  uint64_t ticks;
} gb_emu_context;

// returns the value of the n'th bit of "a"
#define BIT(a, n) ((a & (1 << n)) ? 1 : 0)
// sets the n'th bit of "a" to true(1) or false(0)
#define BIT_SET(a, n, on) (on ? (a) |= (1 << n) : (a) &= ~(1 << n))
// returns true(1) if "a" is between "b" and "c"
#define BETWEEN(a, b, c) ((a >= b) && (a <= c))

int start();
