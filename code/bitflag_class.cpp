#include "experimental/enum"
#include <iostream>

namespace std
{
	template<typename E>
	concept ValidBitflagType = std::scoped_enum<E> && std::is_unsigned_v<std::enum_type_t<E>>;

	template<ValidBitflagType E>
	class enum_bitflag
	{
	public:
		// construction and assignment
		inline enum_bitflag() : e(std::enum_type_t<E>{0}) {}
		inline enum_bitflag(E _e) : e(_e) {}
		inline enum_bitflag(const enum_bitflag& b) { e = std::enum_value(b.e); }
		inline enum_bitflag(const enum_bitflag&& b) { e = std::enum_value(b.e); }
		inline enum_bitflag& operator=(const enum_bitflag b) { e = std::enum_value(b.e); return *this; }
		inline enum_bitflag& operator=(E _e) { e = std::enum_value(_e); return *this; }

		bool is_set() { return (e <=> std::enum_type_t<E>{0}) != 0; }
		bool has_flag(E _e) { return e & _e; }
		void add_flag(E _e) { e |= enum_value(_e); }

		// bitwise operators
		inline bool operator& (E _e) { return e & _e; }

	private:
		std::enum_type_t<E> e {0};
	};
}

enum class MyBitflag : unsigned int {
	val_1 = 0x01U,
	val_2 = 0x02U,
	val_3 = 0x04U,
	val_4 = 0x08U,
	val_5 = 0x10U,
	val_6 = 0x20U,
};

// NOTE: What this probably requires, is a way to ensure that the values placed inside
// the enumeration are valid bitflags, ie. that none of the use the same bits.
// And then again, maybe that's a feature that programmers want? An example:
enum class ShaderType : unsigned int {
	vertex              = 0x01,
	tess_control        = 0x02,
	tess_eval           = 0x04,
	geometry            = 0x08,
	fragment            = 0x10,
	vertex_and_fragment = 0x11,
	all_graphics        = 0x1F
};


int main()
{
	std::enum_bitflag<MyBitflag> test;
	std::cout << "std::enum_bitflag<MyBitflag> test;\n";
	std::cout << "test.is_set(): " << std::boolalpha << test.is_set() << "\n\n";

	test = MyBitflag::val_1;
	std::cout << "test = MyBitflag::val_1\n";
	std::cout << "test.is_set(): " << std::boolalpha << test.is_set() << '\n';
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_2): " << test.has_flag(MyBitflag::val_2) << "\n\n";

	test.add_flag(MyBitflag::val_2);
	std::cout << "test.add_flag(MyBitflag::val_2);";
	std::cout << "test.is_set(): " << std::boolalpha << test.is_set() << '\n';
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_2): " << test.has_flag(MyBitflag::val_2) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_3): " << test.has_flag(MyBitflag::val_3) << "\n\n";

	return 0;
}
