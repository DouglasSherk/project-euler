CC=clang++
RM=rm -rvf
LIBS = \
	-I"/Users/dsherk/algorithms/headers/algorithms" \
	-I"/Users/dsherk/algorithms/headers/adt" \
	-I"/usr/local/Cellar/boost/1.63.0/include" \
	-I"/usr/local/Cellar/gmp/6.1.2/include" \
	-L"/usr/local/lib/" \
	-L${GTEST_DIR} \
	-lgmp \
	-lgtest \
	-isystem ${GTEST_DIR}/include
CC_FLAGS = -g -ggdb -std=c++14 -Werror -Wall -pedantic $(LIBS)
MAKEFLAGS="-j 8"

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.out)

TEST_SRCS = $(wildcard test/headers/*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.out)

all: $(OBJS)
	# $(CC) $< $(CC_FLAGS) $(OBJS) -o $@

test: $(TEST_OBJS)
	for test in test/**/*.out; do ./$$test; done

%.out: %.cpp
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	$(RM) bin *.o *.out *.dSYM test/**/*.dSYM test/**/*.out test/*.dSYM test/*.out
