#ifndef ENGINE_H
#define ENGINE_H

/* Rotate a vector from the spacecraft body frame to another frame:
 * out = R v, where R is a 3x3 rotation matrix. */
enum { DIM = 3 };

/* Every engine provides these three things. The Makefile links exactly one
 * engine, chosen at build time (Power of Ten Rule 9: no function pointers). */
extern const char ENGINE_NAME[];
extern const double ENGINE_TOLERANCE;	/* stated BEFORE qualification */
void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM]);

/* The FP64 reference, always linked, never changed */
void rotate_reference(const double R[DIM][DIM], const double v[DIM], double out[DIM]);

#endif
