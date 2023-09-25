CC := gcc

FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror -Wshadow
CFLAGS := -std=c2x $(FLAGS)

means.o : means.c
	$(CC) $(CFLAGS) -c means.c

homework03.o : homework03.c
	$(CC) $(CFLAGS) -c homework03.c

homework03_objs := homework03.o means.o

homework03 : $(homework03_objs)
	$(CC) $(CFLAGS) -o homework03 $(homework03_objs) -lm


clean:
	rm -rf homework03 *.o *.swp
