#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Three copies of one sensor reading, in hundredths of a degree C */
typedef struct {
	int16_t copy[3];
} tmr_reading;

enum { VOTE_OK = 0, VOTE_NO_QUORUM = -1 };

/* Majority vote. Returns VOTE_OK and the majority value, or VOTE_NO_QUORUM
 * if all three copies disagree. Never guesses. */
int vote(const tmr_reading *r, int16_t *result)
{
	if (r->copy[0] == r->copy[1] || r->copy[0] == r->copy[2]) {
		*result = r->copy[0];
		return VOTE_OK;
	}
	if (r->copy[1] == r->copy[2]) {
		*result = r->copy[1];
		return VOTE_OK;
	}
	return VOTE_NO_QUORUM;
}

/* Simulate a single-event upset: radiation flips one bit */
void flip_bit(int16_t *value, int bit)
{
	*value = (int16_t)((uint16_t)*value ^ (uint16_t)(1U << bit));
}

/* Convert a sensor reading in thousandths of a degree to hundredths */
int16_t to_hundredths(int32_t millidegrees)
{
	return (int16_t)(millidegrees / 10);
}

void show(const char *label, const tmr_reading *r)
{
	int16_t result = 0;
	int status = vote(r, &result);
	fprintf(stdout, "%-34s copies %7d %7d %7d  -> ", label, r->copy[0], r->copy[1], r->copy[2]);
	if (status == VOTE_OK) {
		fprintf(stdout, "vote %7d\n", result);
	}
	else {
		fprintf(stdout, "NO QUORUM: reported, not guessed\n");
	}
}

int main(void)
{
	const int16_t true_value = 2150;	/* 21.50 C */
	tmr_reading r;

	r = (tmr_reading){ { true_value, true_value, true_value } };
	show("1. No faults", &r);

	flip_bit(&r.copy[1], 10);
	show("2. One bit flip, one copy", &r);

	r = (tmr_reading){ { true_value, true_value, true_value } };
	flip_bit(&r.copy[0], 10);
	flip_bit(&r.copy[1], 10);
	show("3. SAME bit flip, two copies", &r);

	r = (tmr_reading){ { true_value, true_value, true_value } };
	flip_bit(&r.copy[0], 10);
	flip_bit(&r.copy[1], 3);
	show("4. DIFFERENT bit flips, two copies", &r);

	/* Three independent sensors all read 350.000 C during a hot burn, but all
	 * three channels run the SAME conversion software */
	const int32_t hot = 350000;
	r = (tmr_reading){ { to_hundredths(hot), to_hundredths(hot), to_hundredths(hot) } };
	show("5. Same software bug, all copies", &r);

	return EXIT_SUCCESS;
}
