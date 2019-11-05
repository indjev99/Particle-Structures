#include "../headers/randomizer.h"

#include <stdlib.h>

long long randll()
{
    return rand() * (RAND_MAX + 1ll) + rand();
}
void seeRandomizer(int seed)
{
    srand(seed);
}
int randomInt(int from, int to)
{
    int range = to - from + 1;
    return randll() % range + from;
}
double randomDouble(double from, double to, double incr)
{
    int intRange = (to - from + incr / 2) / incr + 1;
    return randll() % intRange * incr + from;
}
