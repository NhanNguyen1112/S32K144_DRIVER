
#ifndef __Gpio__
#define __Gpio__

#include "S32K144.h"

void SetPinInput(const unsigned char Port, const unsigned char Pin, const unsigned char Pull);
void SetPinOutput(const unsigned char Port, const unsigned char Pin, const unsigned char Pull);
void WritePin(const unsigned char Port, const unsigned char Pin, const unsigned char Status);
unsigned int GetPin(const unsigned char Port, const unsigned char Pin);
void TogglePin(const unsigned char Port, const unsigned char Pin);

#endif

