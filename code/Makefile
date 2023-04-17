GCC=g++-12
FLG=-std=c++23
HDR=experimental/enum

test1: test1.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

test2: test2.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

color_map: color_map.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

iterate1: iterate1.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

compare_enums: compare_enums.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

clean:
	rm -f test1
