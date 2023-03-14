// ----------------- Histogram.cpp ---------------
#include "Histogram.h"
#include <iostream>
#include "RandomEIntegerGenerator.h"

namespace Hist
{


Histogram::Histogram() : HistogramBase(std::unique_ptr<Logger>(new Logger))
{
	// Set counts to zero.
	clear();
}

Histogram::Histogram(std::unique_ptr<Logger> &logger) : HistogramBase(std::move(logger))
{
	// Set counts to zero.
	clear();
}

Histogram::Histogram(const Histogram& other) : HistogramBase(other)
{
	for (int i = 0; i < Count; ++i)
	{
		v_values[i] = other.v_values[i];
	}
}

Histogram::Histogram(Histogram&& to_be_moved) : HistogramBase(to_be_moved)
{
	for (int i = 0; i < Count; ++i)
	{
		v_values[i] = to_be_moved.v_values[i];
	}
}

void Histogram::add(EInteger value)
{
	if (value >= Zero && value < Count)
	{
		v_values[value]++;
	}	
} // End add.

void Histogram::clear()
{
	for (int i = 0; i < Count; ++i) v_values[i] = 0;
} // End clear.

EInteger Histogram::getMode() const
{
	EInteger res = Zero;
	unsigned int best = 0;
	for (int i = 0; i < Count; ++i)
	{
		if (v_values[i] > best)
		{
			best = v_values[i];
			res = static_cast<EInteger>(i);
		}
	}
	return res;
} // End getMode.

EInteger Histogram::getMinValue() const
{
	EInteger res = Empty;
	for (int i = 0; i < Count; ++i)
	{
		// See if has any.
		if (v_values[i] > 0)
		{
			EInteger cur = static_cast<EInteger>(i);

			// See if error.
			if (res == Empty) res = cur;

			// See if smaller.
			else if (cur < res) res = cur;

		} // End if has any values.
	} // End go through.
	return res;
} // End getMinValue.

EInteger Histogram::getMaxValue() const
{
	EInteger res = Empty;
	for (int i = 0; i < Count; ++i)
	{
		// See if has any.
		if (v_values[i] > 0)
		{
			EInteger cur = static_cast<EInteger>(i);

			// See if error.
			if (res == Empty) res = cur;
			
			// See if bigger.
			else if (cur > res) res = cur;

		} // End if has any values.
	} // End go through.
	return res;
} // End getMaxValue.

void Histogram::print() const
{
	std::cout << "Histogram values (Type, Count):\n";
	for (int i = 0; i < Count; ++i)
	{
		EInteger type = static_cast<EInteger>(i);
		const char *text = get_text_from_type(type);
		unsigned int count = v_values[i];

		std::cout << "  " << text << ", " << count << "\n";
	}
	std::cout << "Calculated values:\n";
	std::cout << "  Modus: " << get_text_from_type(getMode()) << "\n";
	std::cout << "  Min: " << get_text_from_type(getMinValue()) << "\n";
	std::cout << "  Max: " << get_text_from_type(getMaxValue()) << "\n";

} // End print.


void run_test()
{
	Histogram test;

	RandomEintegerGenerator mizer;


	// Adding lots of randomized values.
	{
		for (int i = 0; i < 1000; ++i)
		{
			test.add(mizer());
		}

		std::cout << "==========================\n";
		test.print();
		
	}

	// Adding few values.
	{
		
		test.clear();
		test.add(Two);
		test.add(Zero);
		test.add(One);
		
		std::cout << "==========================\n";
		test.print();
	}

	// Adding one value.
	{
		test.clear();
		test.add(Three);
		std::cout << "==========================\n";
		test.print();
	}

	// Adding incorrect types.
	{
		test.clear();
		test.add(static_cast<EInteger>(99));
		test.add(static_cast<EInteger>(-1));
		test.add(Count);
		test.add(Empty);
		test.add(Error);

		std::cout << "==========================\n";
		test.print();
	}
} // End run_test.



} // End space.
