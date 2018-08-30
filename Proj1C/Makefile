
bin: inc lib
	mkdir -p bin; \
	
	gcc -o bin/cli cli/cli.c -Iinclude -Llib -lmath330 -lm; \

lib:  cos330.o sin330.o tan330.o exp330.o log330.o arccos330.o \
arcsin330.o arctan330.o
	ar -r libmath330.a cos330.o sin330.o tan330.o exp330.o log330.o \
arcsin330.o arctan330.o arccos330.o; \
	mkdir -p lib; \
	cp libmath330.a lib; \
	cp math330.h include; \

cos330.o: trig/cos330.c
	gcc -c -I include trig/cos330.c
sin330.o: trig/sin330.c
	gcc -c -I include trig/sin330.c
tan330.o: trig/tan330.c
	gcc -c -I include trig/tan330.c
exp330.o: exp/exp330.c
	gcc -c -I include exp/exp330.c
log330.o: exp/log330.c
	gcc -c -I include exp/log330.c
arccos330.o: trig/arccos330.c
	gcc -c -I include trig/arccos330.c
arcsin330.o: trig/arcsin330.c
	gcc -c -I include trig/arcsin330.c
arctan330.o: trig/arctan330.c
	gcc -c -I include trig/arctan330.c
inc: 
	mkdir -p include
	cp math330.h include
