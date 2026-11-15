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
 * It also violates Power of Ten Rules 1, 2, and 3. Your job is to fix that.
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

command *cmd_alloc(void)
{
	return (command *)malloc(sizeof(command));
}

void cmd_release(command *cmd)
{
	free(cmd);
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

/* Rule 1: count the commands recursively */
int count_commands(const command *cmd)
{
	if (cmd == NULL) {
		return 0;
	}
	return 1 + count_commands(cmd->next);
}

/* Rule 1: print the commands recursively */
void print_commands(const command *cmd)
{
	if (cmd != NULL) {
		fprintf(stdout, "  id %3d  t=%5d s  %s\n", cmd->id, cmd->exec_time, cmd->opcode);
		print_commands(cmd->next);
	}
}

/* Rule 1: delete the commands recursively */
void delete_commands(command *cmd)
{
	if (cmd != NULL) {
		delete_commands(cmd->next);
		cmd_release(cmd);
	}
}

/* Rule 2: search with no bound. Returns 0 if cancelled, -1 if not found. */
int cancel_command(queue *q, int id)
{
	command *prev = NULL;
	command *curr = q->head;

	while (curr != NULL && curr->id != id) {
		prev = curr;
		curr = curr->next;
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
	while (q->head != NULL) {
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
	if (cancel_command(&q, cancel_id) == 0) {
		fprintf(stdout, "cancelled\n");
	}
	else {
		fprintf(stdout, "not found\n");
	}

	fprintf(stdout, "Executing %d commands:\n", count_commands(q.head));
	execute_all(&q);

	delete_commands(q.head);
	return EXIT_SUCCESS;
}
