#include "experimental/enum"
#include <cstdint>
#include <iostream>


enum class EnumFlags : uint32_t {
	flag_1 = 0x01,
	flag_2 = 0x02,
	flag_4 = 0x04,
	flag_8 = 0x08
};

int main()
{
	constexpr auto flags = EnumFlags::flag_1 | EnumFlags::flag_2;
	static_assert(flags & EnumFlags::flag_1);
	static_assert(!(EnumFlags::flag_8 & flags));

	return 0;
}
