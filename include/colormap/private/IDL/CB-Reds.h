/**
 * This file was automatically created with "create_c++_header.sh".
 * Do not edit manually.
 */
#pragma once
#include "../../colormap.h"

namespace colormap
{
namespace IDL
{

class CBReds : public Colormap
{
private:
	class Wrapper : public WrapperBase
	{
	public:
		#if defined(__clang__)
		#pragma clang diagnostic push
		#pragma clang diagnostic ignored "-Wkeyword-macro"
		#elif defined(__GNUC__)
		#pragma GCC diagnostic push
		
		#endif

		#define float local_real_t
		#include "../../../../shaders/glsl/IDL_CB-Reds.frag"
		#undef float

		#if defined(__clang__)
		#pragma clang diagnostic pop
		#elif defined(__GNUC__)
		#pragma GCC diagnostic pop
		#endif
	};

public:
	Color getColor(double x) const override
	{
		Wrapper w;
		vec4 c = w.colormap(x);
		Color result;
		result.r = std::max(0.0, std::min(1.0, c.r));
		result.g = std::max(0.0, std::min(1.0, c.g));
		result.b = std::max(0.0, std::min(1.0, c.b));
		result.a = std::max(0.0, std::min(1.0, c.a));
		return result;
	}

	std::string getTitle() const override
	{
		return std::string("CB-Reds");
	}

	std::string getCategory() const override
	{
		return std::string("IDL");
	}

	std::string getSource() const override
	{
		return std::string(
			"float colormap_red(float x) {\n"
			"	if (x < 0.7109796106815338) {\n"
			"		return (((-9.58108609441667E+02 * x + 8.89060620527714E+02) * x - 2.42747192807495E+02) * x + 9.97906310565304E+00) * x + 2.54641252219400E+02;\n"
			"	} else {\n"
			"		return ((-9.93985373158007E+02 * x + 1.96524174972026E+03) * x - 1.54068189744713E+03) * x + 6.72947219603874E+02;\n"
			"	}\n"
			"}\n"
			"\n"
			"float colormap_green(float x) {\n"
			"	if (x < 0.7679868638515472) {\n"
			"		return ((((2.66433610509335E+03 * x - 5.05488641558587E+03) * x + 3.69542277742922E+03) * x - 1.36931912848446E+03) * x - 5.12669839132577E+01) * x + 2.41929417192750E+02;\n"
			"	} else {\n"
			"		return (-2.11738816337853E+02 * x + 2.78333107855597E+02) * x - 6.66958752910143E+01;\n"
			"	}\n"
			"}\n"
			"\n"
			"float colormap_blue(float x) {\n"
			"	return (((-6.83475279000297E+02 * x + 1.55250107598171E+03) * x - 9.25799053039285E+02) * x - 1.67380812671938E+02) * x + 2.37145226675143E+02;\n"
			"}\n"
			"\n"
			"vec4 colormap(float x) {\n"
			"	float r = clamp(colormap_red(x) / 255.0, 0.0, 1.0);\n"
			"	float g = clamp(colormap_green(x) / 255.0, 0.0, 1.0);\n"
			"	float b = clamp(colormap_blue(x) / 255.0, 0.0, 1.0);\n"
			"	return vec4(r, g, b, 1.0);\n"
			"}\n"
		);
	}
};

} // namespace IDL
} // namespace colormap
