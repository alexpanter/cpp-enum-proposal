#include "experimental/enum"
#include <cstdint>
#include <iostream>
#include <string_view>
#include <stdexcept>

template<std::scoped_enum T>
class Bitflag
{
	using type = std::enum_type_t<T>;
public:
	Bitflag() { t = type{0}; }
	Bitflag(T _t) { t = std::enum_value<T>(_t); }
	Bitflag(Bitflag& b) { t = b.t; }

	Bitflag& operator= (T _t) { t = std::enum_value<T>(_t); return *this; }
	void operator|=(T _t) { t = t | std::enum_value<T>(_t); }
	type operator()() { return t; }

	bool operator& (T _t) { return t & std::enum_value<T>(_t); }
	bool operator== (const Bitflag& b) { return t == b.t; }

private:
	std::enum_type_t<T> t;
};

enum class DynState : uint32_t
{
	viewport                    = 0x00000001U,
	scissor                     = 0x00000002U,
	line_width                  = 0x00000004U,
	depth_bias                  = 0x00000008U,
	blend_constants             = 0x00000010U,
	depth_bounds                = 0x00000020U,
	stencil_compare_mask        = 0x00000040U,
	stencil_write_mask          = 0x00000080U,
	stencil_reference           = 0x00000100U,
};

/* TESTING */
constexpr std::string_view enum_string(DynState ds)
{
	switch (ds) {
	case DynState::viewport:             return "viewport";
	case DynState::scissor:              return "scissor";
	case DynState::line_width:           return "line_width";
	case DynState::depth_bias:           return "depth_bias";
	case DynState::blend_constants:      return "blend_constants";
	case DynState::depth_bounds:         return "depth_bounds";
	case DynState::stencil_compare_mask: return "stencil_compare_mask";
	case DynState::stencil_write_mask:   return "stencil_write_mask";
	case DynState::stencil_reference:    return "stencil_reference";
	default:
		throw std::runtime_error("Invalid value for enum_string!");
	}
}


int main()
{
	Bitflag<DynState> state;
	std::cout << "Empty bitflag: " << state() << '\n';

	state |= DynState::viewport;
	std::cout << "Added " << enum_string(DynState::viewport) << ": " << state() << '\n';
	std::cout << "Viewport is included: " << std::boolalpha << (state & DynState::viewport) << '\n';

	Bitflag<DynState> state2(state);
	std::cout << "New bitflag copy-constructed: " << state2() << '\n';
	std::cout << "The two bitflags are equivalent: " << std::boolalpha << (state == state2) << '\n';


	return 0;
}
