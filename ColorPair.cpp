#include <iostream>
#include "ColorPair.h"

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate"};
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
    MajorColor majorColor;
    MinorColor minorColor;

    ColorPair::ColorPair(MajorColor major, MinorColor minor)
    {
        majorColor = major;
        minorColor = minor;
    }

    MajorColor ColorPair::getMajor() {return majorColor;}
    MinorColor ColorPair::getMinor() {return minorColor;}
	
	list<ColorPair> PrintColorList()
	  {
      list<ColorPair> colorList;
      for (int i = 1; i <= numberOfMinorColors * numberOfMajorColors; i++)
      {
          ColorPair colorPair = GetColorFromPairNumber(i);
          colorList.push_back(colorPair);
          std::cout << "\t" << i << "\t" << colorPair.ToString() << std::endl;
      }
      return colorList;
  }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
  
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
  
    std::string ColorPair::ToString() {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
}