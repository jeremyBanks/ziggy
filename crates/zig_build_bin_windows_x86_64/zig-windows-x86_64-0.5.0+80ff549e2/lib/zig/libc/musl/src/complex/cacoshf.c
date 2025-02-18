#include "complex_impl.h"

float complex cacoshf(float complex z)
{
	z = cacosf(z);
	return CMPLXF(-cimagf(z), crealf(z));
}
