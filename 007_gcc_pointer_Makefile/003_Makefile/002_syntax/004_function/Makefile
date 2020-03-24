A =  a b c
B = $(foreach f, $(A), $(f).o)

C = a b c d/
D = $(filter %/, $(C))
E = $(filter-out %/, $(C))

files = $(wildcard *.c)

files2 = a.c b.c c.c e.c abc
files3 = $(wildcard $(files2))

def_files = $(patsubst %.c, %.o, $(files2))

all:
	@echo B = $(B)
	@echo D = $(D)
	@echo E = $(E)
	@echo files     = $(files)
	@echo files3    = $(files3)
	@echo def_files = $(def_files)
	