#include <math_lib.hpp>

#include <common/math/add.hpp>

namespace math_lib
{
	double mult2(double x) noexcept
	{
		// Implemented via `common::math::add` to demonstrate dependency direction:
		// mult2(x) = x + x
		return common::math::add(x, x);
	}
} // namespace math_lib
