headers = -I"/Users/dsherk/algorithms/headers/algorithms" -I"/Users/dsherk/algorithms/headers/adt" -I"./headers/boost_1_63_0"
CC_FLAGS = -g -ggdb -std=c++14 -isystem ${GTEST_DIR}/include -L${GTEST_DIR} -lgtest -pthread $(headers)

%: %.cpp
	g++ $(CC_FLAGS) -o $@.out $<
