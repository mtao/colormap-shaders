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

class CBBuGn : public Colormap
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
		#include "../../../../shaders/glsl/IDL_CB-BuGn.frag"
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
		return std::string("CB-BuGn");
	}

	std::string getCategory() const override
	{
		return std::string("IDL");
	}

	std::string getSource() const override
	{
		return std::string(
			"float colormap_red(float x) {\n"
			"	if (x < 0.2494658606560582) {\n"
			"		return (-1.98833893257484E+02 * x - 1.24389159093545E+02) * x + 2.46504720279718E+02;\n"
			"	} else {\n"
			"		return (((-1.85732147540803E+03 * x + 3.95435649372523E+03) * x - 2.78121710759105E+03) * x + 3.94042660425286E+02) * x + 2.23685415320351E+02;\n"
			"	}\n"
			"}\n"
			"\n"
			"float colormap_green(float x) {\n"
			"	if (x < 0.2248314628132282) {\n"
			"		return -6.43489926739916E+01 * x + 2.52449038461538E+02;\n"
			"	} else {\n"
			"		return ((-5.64618971208984E+01 * x - 2.68370957359183E+01) * x - 1.13001580194466E+02) * x + 2.65385956392887E+02;\n"
			"	}\n"
			"}\n"
			"\n"
			"float colormap_blue(float x) {\n"
			"	if (x < 0.8) {\n"
			"		return ((((1.59308890502154E+03 * x - 2.88662249445915E+03) * x + 2.00432779052853E+03) * x - 9.47781545884907E+02) * x + 5.68068034974858E+01) * x + 2.51926935643853E+02;\n"
			"	} else {\n"
			"		return ((-4.08819825327256E+03 * x + 1.13496840066923E+04) * x - 1.06254795336147E+04) * x + 3.39092424595566E+03;\n"
			"	}\n"
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
