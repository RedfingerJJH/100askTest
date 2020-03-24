objs = a.o b.o c.o

CFLAGS = -Werror -Iinclude

dep_files := $(patsubst %,.%.d,$(objs))
dep_files := $(wildward $(dep_files))

test: $(objs)
	gcc -o test $^

ifneq ($(dep_files),)
	include $(dep_files)
endif

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm *.o test

distclean:
	rm $(dep_files)

.PHONY: clean