
// ----------------- RandomEintegerGenerator.h ---------------

#pragma once
#include "HistogramBase.h"


namespace Hist
{


/**
 *  Wichmann-Hill random generator.
 *  If called default constructor, will determine seeds based on time.
 *  Custom seeds set from 1 to 30000. Clamps to range if incorrect parameters.
 */
class RandomEintegerGenerator : public RandomEintegerGeneratorBase
{
public:

	// Creates time seed.
	RandomEintegerGenerator();
	RandomEintegerGenerator(int s1, int s2, int s3);

	EInteger operator()();


private:
	int get_range_int(int min_val, int max_val);
	float get_unit_float();

	int v_s1;
	int v_s2;
	int v_s3;
};
}