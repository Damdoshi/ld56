#include		"sgsplash.h"

double                       efget_value(double                          ratio,
					 double                          min,
					 double                          max)
{
  return ((ratio * (max - min)) + min);
}
