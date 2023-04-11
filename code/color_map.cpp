// NOTE: Same as `test2.cpp`, but showcasing an actual usable scenario
#include "experimental/enum"
#include <map>
#include <optional>

template<std::scoped_enum E, typename T>
class EnumMap {
public:
	bool has_value(E e) { return mEnumMap.contains(e); }
	void add_value(E e, T&& t) { mEnumMap[e] = t; }
	std::optional<T> get_value(E e) {
		if (auto it = mEnumMap.find(e); it != mEnumMap.end()) {
			return { it->second };
		} else { return std::nullopt; }
	}
private:
	std::map<E, T> mEnumMap;
};

enum class ColorChoice { color1, color2, color3, color4 };
struct Color {
	unsigned char red {0U};
	unsigned char green{0U};
	unsigned char blue{0U};
};

using ColorMap = EnumMap<ColorChoice, Color>;

void set_background_color(std::optional<Color>& c) {}
void set_keyword_color(std::optional<Color>& c) {}
void set_number_color(std::optional<Color>& c) {}
void set_foreground_color(std::optional<Color>& c) {}

int main()
{
	ColorMap cmap;

	// configure color scheme
	cmap.add_value(ColorChoice::color1, {255, 0, 0});
	cmap.add_value(ColorChoice::color2, {148, 56, 216});
	cmap.add_value(ColorChoice::color3, {16, 24, 88});
	cmap.add_value(ColorChoice::color4, {255, 255, 255});

	// pseduo function call to simulate a text editor
	std::optional<Color> col1 = cmap.get_value(ColorChoice::color1);
	std::optional<Color> col2 = cmap.get_value(ColorChoice::color2);
	std::optional<Color> col3 = cmap.get_value(ColorChoice::color3);
	std::optional<Color> col4 = cmap.get_value(ColorChoice::color4);
	set_background_color(col1);
	set_keyword_color(col2);
	set_number_color(col3);
	set_foreground_color(col4);
}
