AR = ar
CC = gcc
COMMON = -Iinclude/
ARFLAGS = rsc
LDFLAGS = 
CFLAGS = -Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC

ALIB = cblas/libs/cblas.a
SLIB = cblas/libs/cblas.so
HEADER = cblas/include/cblas.h
INCLUDE = -Icblas/include/
OBJ = dot.o dot_sub.o
OBJS = $(addprefix objs/, $(OBJ))
VPATH = src

all: dir $(ALIB) $(SLIB)

$(ALIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(SLIB): $(OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS)

objs/%.o: %.c include/cblas.h
	$(CC) $(COMMON) $(CFLAGS) -o $@ -c $<

dir:
	mkdir -p objs cblas/include cblas/libs 
	cp include/cblas.h cblas/include/cblas.h

.PHONY: main clean

main: main.o $(ALIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c $(HEADER)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf objs cblas main main.o
