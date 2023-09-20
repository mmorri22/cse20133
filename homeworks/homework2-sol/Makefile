CC := gcc

FLAGS := -g -O2 -Wall -Wextra -Werror -Wconversion -lm
CFLAGS := -std=c2x $(FLAGS)

# Prob1 Objects
Prob1.o: Prob1.c
	$(CC) $(CFLAGS) -c Prob1.c

#Object Variable Name

Prob1_objs := Prob1.o

# Executable
Prob1: $(Prob1_objs)
	$(CC) $(CFLAGS) -o Prob1 $(Prob1_objs) -lm
	./Prob1

# Prob2 Objects
Prob2.o: Prob2.c
	$(CC) $(CFLAGS) -c Prob2.c

#Object Variable Name

Prob2_objs := Prob2.o

# Executable
Prob2: $(Prob2_objs)
	$(CC) $(CFLAGS) -o Prob2 $(Prob2_objs) -lm
	./Prob2

# Prob3 Objects
Prob3.o: Prob3.c
	$(CC) $(CFLAGS) -c Prob3.c

#Object Variable Name

Prob3_objs := Prob3.o

# Executable
Prob3: $(Prob3_objs)
	$(CC) $(CFLAGS) -o Prob3 $(Prob3_objs) -lm
	./Prob3

# Prob4 Objects
Prob4.o: Prob4.c
	$(CC) $(CFLAGS) -c Prob4.c

#Object Variable Name

Prob4_objs := Prob4.o

# Executable
Prob4: $(Prob4_objs)
	$(CC) $(CFLAGS) -o Prob4 $(Prob4_objs) -lm
	./Prob4

# Prob5 Objects
Prob5.o: Prob5.c
	$(CC) $(CFLAGS) -c Prob5.c

#Object Variable Name

Prob5_objs := Prob5.o

# Executable
Prob5: $(Prob5_objs)
	$(CC) $(CFLAGS) -o Prob5 $(Prob5_objs) -lm
	./Prob5


executable_names := Prob1 Prob2 Prob3 Prob4 Prob5

all: $(executable_names)

clean:
	rm -rf *.o *.swp $(executable_names)
