/**
 * This file was automatically created with "create_c++_header.sh".
 * Do not edit manually.
 */
#pragma once
#include "../../colormap.h"

namespace colormap
{
namespace MATLAB
{

class Autumn : public Colormap
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
		#include "../../../../shaders/glsl/MATLAB_autumn.frag"
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
		return std::string("autumn");
	}

	std::string getCategory() const override
	{
		return std::string("MATLAB");
	}

	std::string getSource() const override
	{
		return std::string(
			"vec4 colormap(float x) {\n"
			"    float g = clamp(x, 0.0, 1.0);\n"
			"    return vec4(1.0, g, 0.0, 1.0);\n"
			"}\n"
		);
	}
};

} // namespace MATLAB
} // namespace colormap
