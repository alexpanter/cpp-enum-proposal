#include "experimental/enum"

enum class MyScopedEnum { value_1, value_2, value_3 };

template<std::scoped_enum T>
class MyClass {
public:
	MyClass(T _value) : value(_value) {}
private:
	T value;
};

template<MyScopedEnum T>
class MyClass2 {
	MyScopedEnum value = T;
};

int main()
{
	static_assert(std::scoped_enum<MyScopedEnum>);
	MyClass<MyScopedEnum> myClass(MyScopedEnum::value_1);
	MyClass2<MyScopedEnum::value_1> myClass2;
	// MyClass<int> myClass(23); // -- fails to compile!
}
