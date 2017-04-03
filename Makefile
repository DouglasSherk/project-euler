headers = \
	-I"/Users/dsherk/algorithms/headers/algorithms" \
	-I"/Users/dsherk/algorithms/headers/adt" \
	-I"/usr/local/Cellar/boost/1.63.0/include" \
	-I"/usr/local/Cellar/gmp/6.1.2/include"
objects = -L"/usr/local/lib/" -L${GTEST_DIR} -lgmp
CC_FLAGS = -g -ggdb -std=c++14 -isystem ${GTEST_DIR}/include $(objects) -lgtest -pthread $(headers) 

%: %.cpp
	g++ $(CC_FLAGS) -o $@.out $<
