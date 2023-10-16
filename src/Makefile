OBJS= tokenizer.o uimain.o history.o

CFLAGS=-g -O3

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenize

run:tokenize
	./tokenize
