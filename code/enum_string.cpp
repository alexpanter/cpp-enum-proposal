#include "experimental/enum"
#include <iostream>
#include <string_view>
#include <limits>

enum class GraphicsApiType { none, opengl, vulkan };

namespace std
{
	template<GraphicsApiType E>
	constexpr string_view enum_string();

	template<>
	constexpr string_view enum_string<GraphicsApiType::none>()
	{
		return "none";
	}

	template<>
	constexpr string_view enum_string<GraphicsApiType::opengl>()
	{
		return "opengl";
	}

	template<>
	constexpr string_view enum_string<GraphicsApiType::vulkan>()
	{
		return "vulkan";
	}
}



int main()
{
	std::cout << std::enum_string<GraphicsApiType::none>() << '\n';
	std::cout << std::enum_string<GraphicsApiType::opengl>() << '\n';
	std::cout << std::enum_string<GraphicsApiType::vulkan>() << '\n';

	std::cout << "int max: " << std::numeric_limits<int>::max() << '\n';

	return 0;
}
