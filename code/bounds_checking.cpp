#include "experimental/enum"
#include <iostream>

enum class MyScopedEnum
{
	value_0, value_1, value_2, value_3, value_4, value_5
};

template<typename E>
concept IsMyScopedEnum = std::is_same_v<E, MyScopedEnum> && std::scoped_enum<E>;

template<std::scoped_enum E>
struct enum_cardinality;

template<std::scoped_enum E>
requires IsMyScopedEnum<E>
struct enum_cardinality<E>
{
	static constexpr std::enum_type_t<E> value = 6;
};

template<std::scoped_enum E>
requires IsMyScopedEnum<E>
constexpr bool enum_bounded(std::enum_type_t<E> val)
{
	return ((val <=> 0) >= 0) && ((val <=> enum_cardinality<E>::value) <= 0);
}

void print_bounded(int val)
{
	std::cout << std::boolalpha << "enum_bounded(" << val << "): "
	          << enum_bounded<MyScopedEnum>(val) << '\n';
}


int main()
{
	std::cout << "enum_cardinality_v<MyScopedEnum>: " << enum_cardinality<MyScopedEnum>::value << '\n';
	print_bounded(-1);
	print_bounded(0);
	print_bounded(1);
	print_bounded(2);
	print_bounded(3);
	print_bounded(4);
	print_bounded(5);
	print_bounded(6);
	print_bounded(7);

	return 0;
}
