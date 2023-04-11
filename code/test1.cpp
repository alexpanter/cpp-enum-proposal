#include "experimental/enum"

enum class MyScopedEnum { value_1, value_2, value_3 };

template<std::scoped_enum T>
class MyClass {
public:
	MyClass(T _value) : value(_value) {}
private:
	T value;
};

int main()
{
	static_assert(std::scoped_enum<MyScopedEnum>);
	MyClass<MyScopedEnum> myClass(MyScopedEnum::value_1);
	// MyClass<int> myClass(23); // -- fails to compile!
}
