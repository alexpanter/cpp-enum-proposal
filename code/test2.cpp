#include "experimental/enum"
#include <cassert>
#include <map>
#include <optional>

enum class MyScopedEnum { value_1, value_2, value_3 };

template<std::scoped_enum E, typename T>
class EnumMap {
public:
	bool has_value(E e) { return mEnumMap.contains(e); }
	void add_value(E e, T&& t) { mEnumMap[e] = t; }
	std::optional<T> get_value(E e) {
		if (auto it = mEnumMap.find(e); it != mEnumMap.end()) {
			return { it };
		} else { return std::nullopt; }
	}
private:
	std::map<E, T> mEnumMap;
};

int main()
{
	EnumMap<MyScopedEnum, int> myMap;
	assert(!myMap.has_value(MyScopedEnum::value_1));
	myMap.add_value(MyScopedEnum::value_1, 1);
	assert(myMap.has_value(MyScopedEnum::value_1));

	std::optional<int> val1 = myMap.get_value(MyScopedEnum::value_1);
	assert(val1.has_value());
	assert(val1.value() == 1);

	std::optional<int> val2 = myMap.get_value(MyScopedEnum::value_2);
	assert(!val2.has_value());
}
