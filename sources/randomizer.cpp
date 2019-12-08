#include "../headers/randomizer.h"

#include <stdlib.h>

long long randll()
{
    return rand() * (RAND_MAX + 1ll) + rand();
}
void seedRandomizer(int seed)
{
    srand(seed);
}
int getRandomizerSeed()
{
    int seed = rand();
    srand(seed);
    return seed;
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
