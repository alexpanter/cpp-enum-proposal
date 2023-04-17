#include "experimental/enum"
#include <cassert>
#include <iostream>

enum class MyScopedEnum : int
{
	value_0 = 0,
	value_1 = 1,
	value_2 = 2,
	value_3 = 3,
	value_43 = 43,
	value_57 = 57
};




int main()
{
	auto clever_fun = [](int a) -> int
	{
		return a + 5;
	};
	std::cout << "clever_fun: " << clever_fun(1) << '\n';

	MyScopedEnum e0 = MyScopedEnum::value_0;
	bool equal = (e0 <=> 0) == 0;
	assert(equal);

	bool equal2 = (0 <=> e0) == 0;
	assert(equal);

	MyScopedEnum e2 = MyScopedEnum::value_2;
	bool less = (1 <=> e2) < 0;
	assert(less);
	bool greater = (e2 <=> 1) > 0;
	assert(greater);

	std::enum_type_t<MyScopedEnum> i = 5;
	// std::enum_type_t<MyScopedEnum::value_0> j = 6;

	auto value3 = std::enum_value(MyScopedEnum::value_3);
	std::cout << "enum_value<value_3>: " << value3 << '\n';

	constexpr auto ordering = MyScopedEnum::value_3 <=> MyScopedEnum::value_43;
	static_assert(ordering < 0);

	return 0;
}
