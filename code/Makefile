GCC=g++-12
FLG=-std=c++23
HDR=experimental/enum

test1: test1.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

test2: test1.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

clean:
	rm -f test1
