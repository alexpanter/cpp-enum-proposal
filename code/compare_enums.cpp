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

void print_enum_value(MyScopedEnum e)
{
	std::cout << "print_enum_value: " << std::enum_value(e) << '\n';
}

int main()
{
	auto clever_fun = [](int a) -> int
	{
		return a + 5;
	};
	std::cout << "clever_fun: " << clever_fun(1) << '\n';

	constexpr MyScopedEnum e0 = MyScopedEnum::value_0;
	constexpr bool equal = (e0 <=> 0) == 0;
	assert(equal);

	constexpr bool equal2 = (0 <=> e0) == 0;
	static_assert(equal);

	static_assert((1 <=> MyScopedEnum::value_2) < 0);
	static_assert((MyScopedEnum::value_2 <=> 1) > 0);

	std::enum_type_t<MyScopedEnum> i = 5;
	// std::enum_type_t<MyScopedEnum::value_0> j = 6;

	auto value3 = std::enum_value(MyScopedEnum::value_3);
	std::cout << "enum_value<value_3>: " << value3 << '\n';

	constexpr auto ordering = static_cast<MyScopedEnum>(3) <=> MyScopedEnum::value_43;
	static_assert(ordering < 0);

	print_enum_value(MyScopedEnum::value_57);
	print_enum_value(static_cast<MyScopedEnum>(56));

	auto ordering2 = MyScopedEnum::value_57 <=> 42;
	if (ordering2 > 0) {
		std::cout << "success!\n";
	} else {
		std::cout << "failure!\n";
	}

	constexpr MyScopedEnum test = static_cast<MyScopedEnum>(56);

	return 0;
}
