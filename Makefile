CC = gcc
CFLAGS = -g -fPIC -std=c11 -pedantic -Wall -Wextra
MODULES=htab_hash_function.o htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_item_init.o htab_item_free.o htab_statistics.o

run: all
all: tail wordcount wordcount-dynamic

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o tail
libhtab.so: $(MODULES)
	$(CC) $(CFLAGS) -shared -o $@ $^
libhtab.a: $(MODULES)
	ar crs $@ $^
wordcount: wordcount.c libhtab.a io.c io.h
	$(CC) $(CFLAGS) -static wordcount.c io.c -o wordcount -L. -lhtab
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) -o $@ wordcount.o io.o -L. -lhtab
clean:
	rm $(MODULES) libhtab.so libhtab.a tail wordcount wordcount-dynamic