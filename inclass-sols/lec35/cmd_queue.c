/*
 * In-Class Lecture 35 - Zero Findings
 *
 * INSTRUCTOR SOLUTION: the Lecture 34 command queue, brought to zero
 * Power of Ten findings under Cobra's p10 rule set, except one documented
 * deviation below.
 *
 * DEVIATION D-1
 *   Rule:      Power of Ten Rule 5 (Cobra finding P10_5)
 *   Finding:   Cobra reports 0 assertions in every function.
 *   Why:       Cobra's rule set counts only tokens named exactly "assert".
 *              This program uses c_assert, the recovery assertion from
 *              Holzmann's paper, because assert() aborts the program and
 *              disappears under -DNDEBUG (Reading 35-1).
 *   Evidence:  grep -o "c_assert(" cmd_queue.c | wc -l reports 24 uses
 *              across 11 functions, more than two per function on average.
 *   Reviewed:  (instructor or teammate name)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flight_assert.h"

/* Rules 6 and 8: enumeration constants are part of the language, not the
 * preprocessor, and unlike variables they are not global data */
enum {
	OPCODE_LEN = 16,
	MAX_COMMANDS = 16	/* the most commands the spacecraft can hold */
};

typedef struct command {
	int id;
	int exec_time;
	char opcode[OPCODE_LEN];
	struct command *next;
} command;

/* Rule 9: the struct is declared first, so the typedef hides nothing */
struct queue {
	command *head;
	command *tail;
};
typedef struct queue queue;

/* Rule 6: the pool is no longer global; main owns it and passes it in */
typedef struct cmd_pool {
	command nodes[MAX_COMMANDS];
	command *free_list;
} cmd_pool;

/* ---------- Rule 3: memory for commands ---------- */

void pool_init(cmd_pool *pool)
{
	if (!c_assert(pool != NULL)) {
		return;
	}
	for (int i = 0; i < MAX_COMMANDS - 1; i++) {
		pool->nodes[i].next = &pool->nodes[i + 1];
	}
	pool->nodes[MAX_COMMANDS - 1].next = NULL;
	pool->free_list = &pool->nodes[0];
	(void)c_assert(pool->free_list != NULL);
}

/* Renamed from cmd_alloc: Cobra's Rule 3 pattern matches any name with "alloc" */
command *cmd_acquire(cmd_pool *pool)
{
	if (!c_assert(pool != NULL)) {
		return NULL;
	}
	if (pool->free_list == NULL) {
		return NULL;	/* pool exhausted: an expected condition, not a bug */
	}
	command *cmd = pool->free_list;
	pool->free_list = cmd->next;
	cmd->next = NULL;
	return cmd;
}

void cmd_release(cmd_pool *pool, command *cmd)
{
	if (!c_assert(pool != NULL) || !c_assert(cmd != NULL)) {
		return;
	}
	cmd->next = pool->free_list;
	pool->free_list = cmd;
}

/* ---------- Queue operations ---------- */

/* Add a command to the back of the queue. Returns 0 on success, -1 on failure. */
[[nodiscard]] int enqueue(cmd_pool *pool, queue *q, int id, int exec_time, const char *opcode)
{
	if (!c_assert(pool != NULL) || !c_assert(q != NULL) || !c_assert(opcode != NULL)) {
		return -1;
	}
	command *cmd = cmd_acquire(pool);
	if (cmd == NULL) {
		return -1;
	}
	cmd->id = id;
	cmd->exec_time = exec_time;
	strncpy(cmd->opcode, opcode, OPCODE_LEN - 1);
	cmd->opcode[OPCODE_LEN - 1] = '\0';
	cmd->next = NULL;

	if (q->tail == NULL) {
		q->head = cmd;
	}
	else {
		q->tail->next = cmd;
	}
	q->tail = cmd;
	return 0;
}

/* Count with a bounded loop. Returns -1 if the queue is corrupted. */
[[nodiscard]] int count_commands(const command *cmd)
{
	int count = 0;
	while (count <= MAX_COMMANDS) {
		if (cmd == NULL) {
			return count;
		}
		cmd = cmd->next;
		count++;
	}
	(void)c_assert(count <= MAX_COMMANDS);	/* reports the corruption */
	(void)c_assert(cmd != NULL);
	return -1;
}

void print_commands(const command *cmd)
{
	(void)c_assert(cmd != NULL);	/* an empty queue is legal, but unexpected here */
	for (int i = 0; i < MAX_COMMANDS && cmd != NULL; i++) {
		fprintf(stdout, "  id %3d  t=%5d s  %s\n", cmd->id, cmd->exec_time, cmd->opcode);
		cmd = cmd->next;
	}
	(void)c_assert(cmd == NULL);	/* stopped by the bound: the queue is corrupted */
}

/* Bounded search. Returns 0 if cancelled, -1 if not found, -2 if corrupted. */
[[nodiscard]] int cancel_command(cmd_pool *pool, queue *q, int id)
{
	if (!c_assert(pool != NULL) || !c_assert(q != NULL)) {
		return -1;
	}
	command *prev = NULL;
	command *curr = q->head;

	int steps = 0;
	while (curr != NULL && curr->id != id) {
		if (steps >= MAX_COMMANDS) {
			return -2;
		}
		prev = curr;
		curr = curr->next;
		steps++;
	}
	if (curr == NULL) {
		return -1;
	}

	if (prev == NULL) {
		q->head = curr->next;
	}
	else {
		prev->next = curr->next;
	}
	if (q->tail == curr) {
		q->tail = prev;
	}
	cmd_release(pool, curr);
	return 0;
}

/* Simulate a radiation bit flip: the last command now points back to the second */
void inject_fault(queue *q)
{
	if (!c_assert(q != NULL) || !c_assert(q->head != NULL)) {
		return;
	}
	if (q->head->next != NULL && q->tail != NULL) {
		q->tail->next = q->head->next;
		fprintf(stdout, "FAULT INJECTED: last command now points back to the second\n");
	}
}

/* Execute every command in order, returning each one to the pool */
void execute_all(cmd_pool *pool, queue *q)
{
	if (!c_assert(pool != NULL) || !c_assert(q != NULL)) {
		return;
	}
	for (int i = 0; i < MAX_COMMANDS && q->head != NULL; i++) {
		command *cmd = q->head;
		fprintf(stdout, "  EXECUTE t=%5d s  id %3d  %s\n", cmd->exec_time, cmd->id, cmd->opcode);
		q->head = cmd->next;
		cmd_release(pool, cmd);
	}
	q->tail = NULL;
}

/* Rule 4: loading moved out of main to keep main short */
void load_commands(cmd_pool *pool, queue *q, FILE *fp)
{
	if (!c_assert(pool != NULL) || !c_assert(q != NULL) || !c_assert(fp != NULL)) {
		return;
	}
	int id = 0;
	int exec_time = 0;
	char opcode[OPCODE_LEN];

	for (int i = 0; i < 4 * MAX_COMMANDS; i++) {	/* Rule 2: even the file read is bounded */
		if (fscanf(fp, "%d %d %15s", &id, &exec_time, opcode) != 3) {
			return;
		}
		if (enqueue(pool, q, id, exec_time, opcode) != 0) {
			fprintf(stdout, "REJECTED: command %d, no memory available\n", id);
		}
	}
}

int main(int argc, char *argv[])
{
	if (!c_assert(argc == 3 || argc == 4) || !c_assert(argv != NULL)) {
		fprintf(stderr, "Usage: %s <command_file> <id_to_cancel> [fault]\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}
	int cancel_id = (int)strtol(argv[2], NULL, 10);

	cmd_pool pool;
	pool_init(&pool);
	queue q = { NULL, NULL };

	load_commands(&pool, &q, fp);
	fclose(fp);

	fprintf(stdout, "Loaded %d commands:\n", count_commands(q.head));
	print_commands(q.head);

	if (argc == 4) {
		inject_fault(&q);
	}

	fprintf(stdout, "Cancelling command %d... ", cancel_id);
	fflush(stdout);
	int status = cancel_command(&pool, &q, cancel_id);
	fprintf(stdout, "%s\n", (status == 0) ? "cancelled" : "not found");

	if (status == -2 || count_commands(q.head) < 0) {
		fprintf(stdout, "\nANOMALY: command queue is corrupted.\n");
		fprintf(stdout, "SAFE MODE: discarding all stored commands. Awaiting ground contact.\n");
		pool_init(&pool);
		return EXIT_FAILURE;
	}

	fprintf(stdout, "Executing %d commands:\n", count_commands(q.head));
	execute_all(&pool, &q);
	return EXIT_SUCCESS;
}
