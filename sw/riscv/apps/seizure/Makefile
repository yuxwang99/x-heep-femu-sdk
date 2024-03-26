CC := gcc
CFLAGS := -Wall -g -Wextra -std=c11
LDFLAGS := -lm

# COMP_FOLDER := Yuxuan_iterative_test_single
# SRCS := main_single.c
# EXECUTABLE := IterPlus_seizure_single

COMP_FOLDER := INCLASS_iterative_test_single
SRCS := examples_single/main.c
EXECUTABLE := Iterative_seizure_single


 SRCS += $(wildcard ${COMP_FOLDER}/*.c)
# SRCS += $(wildcard ${COMP_FOLDER}/INCLASS_iterative_test_single_emx*.c)
# OBJS := $(SRCS:.c=.o)


all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CC) $(CFLAGS) \
		-I ${COMP_FOLDER} \
		-I include \
		$^ -o $@ $(LDFLAGS)

# %.o: %.c
# 	$(CC) $(CFLAGS) \
# 		-I ${COMP_FOLDER} \
# 		-I include \
# 		-c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
