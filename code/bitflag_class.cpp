#include "experimental/enum"
#include <iostream>

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
	std::enum_bitmask<MyBitflag> test;
	std::cout << "std::enum_bitmask<MyBitflag> test;\n";
	std::cout << "test.empty(): " << std::boolalpha << test.empty() << "\n\n";

	test = MyBitflag::val_1;
	std::cout << "test = MyBitflag::val_1\n";
	std::cout << "test.empty(): " << std::boolalpha << test.empty() << '\n';
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_2): " << test.has_flag(MyBitflag::val_2) << "\n\n";

	test.add_flag(MyBitflag::val_2);
	std::cout << "test.add_flag(MyBitflag::val_2);";
	std::cout << "test.empty(): " << std::boolalpha << test.empty() << '\n';
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_2): " << test.has_flag(MyBitflag::val_2) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_3): " << test.has_flag(MyBitflag::val_3) << "\n\n";

	bool has_1 = test & MyBitflag::val_1;
	std::cout << "(test & MyBitflag::val_1): " << (test & MyBitflag::val_1) << '\n';
	std::cout << "(test & MyBitflag::val_4): " << (test & MyBitflag::val_4) << '\n';

	test = MyBitflag::val_6;
	std::cout << "test = MyBitflag::val_6\n";
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_6): " << test.has_flag(MyBitflag::val_6) << "\n\n";

	test |= MyBitflag::val_5;
	std::cout << "test |= MyBitflag::val_5\n";
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_5): " << test.has_flag(MyBitflag::val_5) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_6): " << test.has_flag(MyBitflag::val_6) << "\n\n";

	test.clear();
	std::cout << "test.clear()\n";
	std::cout << "test.empty(): " << test.empty() << "\n\n";

	test
		= MyBitflag::val_1
		| MyBitflag::val_2
		| MyBitflag::val_3
		| MyBitflag::val_4
		| MyBitflag::val_6;
	std::cout << "test = val_1 | val_2 | val_3 | val_4 | val_6\n";
	std::cout << "test.has_flag(MyBitflag::val_1): " << test.has_flag(MyBitflag::val_1) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_2): " << test.has_flag(MyBitflag::val_2) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_3): " << test.has_flag(MyBitflag::val_3) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_4): " << test.has_flag(MyBitflag::val_4) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_5): " << test.has_flag(MyBitflag::val_5) << '\n';
	std::cout << "test.has_flag(MyBitflag::val_6): " << test.has_flag(MyBitflag::val_6) << "\n\n";

	return 0;
}
