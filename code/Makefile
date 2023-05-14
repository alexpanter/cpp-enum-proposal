GCC=g++-12
FLG=-std=c++23
HDR=experimental/enum

all: test1 test2 color_map iterate1 compare_enums bitflag_enums \
	bitflag_type bounds_checking bitflag_class

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

bitflag_enums: bitflag_enums.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

bitflag_type: bitflag_type.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

bounds_checking: bounds_checking.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

bitflag_class: bitflag_class.cpp ${HDR}
	${GCC} ${FLG} $< -o $@

clean:
	rm -f test1
