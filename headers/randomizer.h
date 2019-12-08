#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

#include <vector>

void seedRandomizer(int seed);
int getRandomizerSeed();
int randomInt(int from, int to);
double randomDouble(double from, double to, double incr=0.001);
template <class T>
const T& selectRandom(const std::vector<T>& v)
{
    return v[randomInt(0, v.size()-1)];
}

#endif // RANDOMIZER_H_INCLUDED
