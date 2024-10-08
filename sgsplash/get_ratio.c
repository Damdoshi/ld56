#include			"sgsplash.h"

double                          efget_ratio(double                          value,
					    double                          min,
					    double                          max)
{
    return (((value - min) / (max - min)));
}
