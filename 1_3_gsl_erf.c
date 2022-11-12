#include "allheads.h"

int main()
{
  double bottom_tail =  gsl_cdf_gaussian_P(-1.96, 1);
  printf("Area between [-1.96, 1.96]: %g\n", 1-2*bottom_tail);
}
