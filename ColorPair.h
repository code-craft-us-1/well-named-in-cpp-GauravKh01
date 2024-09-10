#include <string>
#include <list>
#include "ColorCoder.h"

namespace TelCoColorCoder
{
    class ColorPair {
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajor();
        MinorColor getMinor();

        std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);

    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
	
	    list<ColorPair> PrintColorList();
}