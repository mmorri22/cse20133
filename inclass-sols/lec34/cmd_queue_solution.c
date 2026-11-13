/*
 * In-Class Lecture 34 - Making a Command Queue Flight-Ready
 *
 * A spacecraft receives commands from the ground and executes them in order.
 * Each line of the input file is one command:
 *     <command_id> <execution_time_s> <opcode>
 *
 * This program loads the commands into a queue, cancels one command by ID,
 * then executes the rest in order. It works on commands.txt.
 *
 * INSTRUCTOR SOLUTION: complies with Power of Ten Rules 1, 2, and 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPCODE_LEN 16
#define MAX_COMMANDS 16		/* the most commands the spacecraft can hold */

typedef struct command {
	int id;
	int exec_time;
	char opcode[OPCODE_LEN];
	struct command *next;
} command;

typedef struct queue {
	command *head;
	command *tail;
} queue;

/* ---------- Rule 3: memory for commands ---------- */

/* Every command the spacecraft can ever hold, reserved at startup */
static command pool[MAX_COMMANDS];
static command *free_list = NULL;

/* Called once at startup, and again to clear a corrupted queue */
void pool_init(void)
{
	for (int i = 0; i < MAX_COMMANDS - 1; i++) {
		pool[i].next = &pool[i + 1];
	}
	pool[MAX_COMMANDS - 1].next = NULL;
	free_list = &pool[0];
}

command *cmd_alloc(void)
{
	if (free_list == NULL) {
		return NULL;
	}
	command *cmd = free_list;
	free_list = free_list->next;
	cmd->next = NULL;
	return cmd;
}

void cmd_release(command *cmd)
{
	if (cmd != NULL) {
		cmd->next = free_list;
		free_list = cmd;
	}
}

/* ---------- Queue operations ---------- */

/* Add a command to the back of the queue. Returns 0 on success, -1 on failure. */
int enqueue(queue *q, int id, int exec_time, const char *opcode)
{
	command *cmd = cmd_alloc();
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

/* Rules 1 and 2: count with a bounded loop. Returns -1 if the queue is corrupted. */
int count_commands(const command *cmd)
{
	for (int count = 0; count <= MAX_COMMANDS; count++) {
		if (cmd == NULL) {
			return count;
		}
		cmd = cmd->next;
	}
	return -1;	/* more commands than the pool holds: the queue is corrupted */
}

/* Rules 1 and 2: print with a bounded loop */
void print_commands(const command *cmd)
{
	for (int i = 0; i < MAX_COMMANDS && cmd != NULL; i++) {
		fprintf(stdout, "  id %3d  t=%5d s  %s\n", cmd->id, cmd->exec_time, cmd->opcode);
		cmd = cmd->next;
	}
}

/* Rule 2: bounded search.
 * Returns 0 if cancelled, -1 if not found, -2 if the queue is corrupted. */
int cancel_command(queue *q, int id)
{
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
	cmd_release(curr);
	return 0;
}

/* Simulate a radiation bit flip: the last command now points back to the second */
void inject_fault(queue *q)
{
	if (q->head != NULL && q->head->next != NULL && q->tail != NULL) {
		q->tail->next = q->head->next;
		fprintf(stdout, "FAULT INJECTED: last command now points back to the second\n");
	}
}

/* Execute every command in order, removing each one from the queue */
void execute_all(queue *q)
{
	for (int i = 0; i < MAX_COMMANDS && q->head != NULL; i++) {
		command *cmd = q->head;
		fprintf(stdout, "  EXECUTE t=%5d s  id %3d  %s\n", cmd->exec_time, cmd->id, cmd->opcode);
		q->head = cmd->next;
		cmd_release(cmd);
	}
	q->tail = NULL;
}

int main(int argc, char *argv[])
{
	if (argc != 3 && argc != 4) {
		fprintf(stderr, "Usage: %s <command_file> <id_to_cancel> [fault]\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}
	int cancel_id = (int)strtol(argv[2], NULL, 10);

	pool_init();
	queue q = { NULL, NULL };
	int id = 0;
	int exec_time = 0;
	char opcode[OPCODE_LEN];

	while (fscanf(fp, "%d %d %15s", &id, &exec_time, opcode) == 3) {
		if (enqueue(&q, id, exec_time, opcode) != 0) {
			fprintf(stdout, "REJECTED: command %d, no memory available\n", id);
		}
	}
	fclose(fp);

	fprintf(stdout, "Loaded %d commands:\n", count_commands(q.head));
	print_commands(q.head);

	if (argc == 4) {
		inject_fault(&q);
	}

	fprintf(stdout, "Cancelling command %d... ", cancel_id);
	fflush(stdout);
	int status = cancel_command(&q, cancel_id);
	if (status == 0) {
		fprintf(stdout, "cancelled\n");
	}
	else if (status == -1) {
		fprintf(stdout, "not found\n");
	}

	/* A corrupted queue cannot be trusted: discard it and enter safe mode */
	if (status == -2 || count_commands(q.head) < 0) {
		fprintf(stdout, "\nANOMALY: command queue is corrupted.\n");
		fprintf(stdout, "SAFE MODE: discarding all stored commands. Awaiting ground contact.\n");
		pool_init();
		return EXIT_FAILURE;
	}

	fprintf(stdout, "Executing %d commands:\n", count_commands(q.head));
	execute_all(&q);

	/* No delete step: the pool is static, and execute_all returned every node */
	return EXIT_SUCCESS;
}
