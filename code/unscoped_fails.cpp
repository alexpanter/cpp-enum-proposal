#include <iostream>
#include "experimental/enum"

enum MyUnscopedEnum {
	val_0 = 0, val_1 = 1, val_4 = 4
};
enum AnotherUnscopedEnum {
	val_5 = 5, val_6 = 6
};

enum class MyScopedEnum {
	val_0 = 0, val_1 = 1, val_4 = 4
};
enum class AnotherScopedEnum {
	val_5 = 5, val_6 = 6
};



int main()
{
	MyUnscopedEnum e1 = static_cast<MyUnscopedEnum>(2);
	MyUnscopedEnum e2 = static_cast<MyUnscopedEnum>(val_5);
	int k = val_0;
	//int m = val_0 | val_5;

	// Fails to compile
	//int p = MyScopedEnum::val_0 | AnotherScopedEnum::val_5;

	int q = std::enum_value(MyScopedEnum::val_0) | std::enum_value(AnotherScopedEnum::val_5);

	return 0;
}
