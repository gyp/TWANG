#include <Arduino.h>

#include "iSin.h"

int iSin::convert(long x)
{
    boolean pos = true;  // positive - keeps an eye on the sign.
    if (x < 0)
    {
        x = -x;
        pos = !pos;
    }
    if (x >= 360) x %= 360;
    if (x > 180)
    {
        x -= 180;
        pos = !pos;
    }
    if (x > 90) x = 180 - x;
    if (pos) return pgm_read_byte_near(isinTable8[x])/2 ;
    return -isinTable8[x]/2 ;
}

