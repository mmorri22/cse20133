#ifndef EPSILON_H
#define EPSILON_H

/* Experimentally measure machine epsilon for double.
 * Stores the number of halvings in *halvings and returns epsilon. */
double double_epsilon(int *halvings);

/* Experimentally measure machine epsilon for long double.
 * Stores the number of halvings in *halvings and returns epsilon. */
long double long_double_epsilon(int *halvings);

#endif
