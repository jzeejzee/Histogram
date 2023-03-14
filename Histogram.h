// ----------------- Histogram.h ---------------
#pragma once
#include "HistogramBase.h"

namespace Hist
{
	/**
	 * Class Histogram using closed set of enumerated numbers.
	 * Function add will check if given EInteger is within range. If not within range, won't add anything.
	 * getMinValue and getMaxValue will return Empty, if nothing added yet.
	 * getMode will return the smallest value if tied. Returns Zero if nothing added yet.
	 */ 
	class Histogram : public HistogramBase
	{
	public:

		Histogram();
		Histogram(std::unique_ptr<Logger> &);
		Histogram(const Histogram&);
		Histogram(Histogram&&);

		void add(EInteger);
		void clear();

		EInteger getMode() const;
		EInteger getMinValue() const;
		EInteger getMaxValue() const;

		void print() const;

	private:
		unsigned int v_values[Count];

	}; // End Histogram.


	void run_test();


} // End space.