#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

void seed_randomizer(int seed);
int random_int(int from, int to);
double random_double(double from, double to, double incr=0.001);

#endif // RANDOMIZER_H_INCLUDED
