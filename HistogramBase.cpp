
// ----------------- HistogramBase.cpp ---------------

#include "HistogramBase.h"
#include <iostream>
#include <math.h>
#include <algorithm>

namespace Hist
{

const char *get_text_from_type(EInteger type)
{
	switch (type)
	{
		case Zero: return "Zero"; break;
		case One: return "One"; break;
		case Two: return "Two"; break;
		case Three: return "Three"; break;
		case Four: return "Four"; break;

		case Count: return "Count"; break;
		case Empty: return "Empty"; break;

		default: return "Error"; break;

	} // End switch.
} // End get_text_from_type.

//====================================================================================


//====================================================================================
// BASE.

HistogramBase::HistogramBase(std::unique_ptr<Logger> logger) : m_log(std::move(logger))
{
}


HistogramBase::HistogramBase(const HistogramBase& other_ref)
{
	// Create new logger.
	m_log = std::unique_ptr<Logger>(new Logger(*other_ref.m_log.get()) );
}

HistogramBase::HistogramBase(HistogramBase&& other_ref)
{
	m_log = std::move(other_ref.m_log);
}

HistogramBase::~HistogramBase()
{

}


} // End space.

