// ----------------- RandomEintegerGenerator.cpp ---------------

#include "RandomEIntegerGenerator.h"
#include <math.h>
#include <algorithm>

namespace Hist
{



RandomEintegerGenerator::RandomEintegerGenerator()
{
	int64_t val = static_cast<int64_t>(time(NULL));
	val %= 30000;
	val += 1; // Can't be zero.
	v_s1 = v_s2 = v_s3 = static_cast<int>(val);
}
RandomEintegerGenerator::RandomEintegerGenerator(int s1, int s2, int s3)
{
	v_s1 = std::min(std::max(1, s1), 30000);
	v_s2 = std::min(std::max(1, s2), 30000);
	v_s3 = std::min(std::max(1, s3), 30000);
}

int RandomEintegerGenerator::get_range_int(int min_val, int max_val)
{
	int dif = (max_val - min_val + 1);
	float val = get_unit_float() * dif;
	int i_val = (int)floorf(val);
	i_val %= dif;
	int res = min_val + i_val;
	return res;
}

float RandomEintegerGenerator::get_unit_float()
{
	v_s1 = (171 * v_s1) % 30269;
	v_s2 = (172 * v_s2) % 30307;
	v_s3 = (170 * v_s3) % 30323;
	return fmodf(v_s1 / 30269.0f + v_s2 / 30307.0 + v_s2 / 30323.0f, 1.0f);
} // End get_unit_float.

EInteger RandomEintegerGenerator::operator()()
{
	int val = get_range_int(0, Count-1);
	return static_cast<EInteger>(val);
} // End operator()().

} // End space.
