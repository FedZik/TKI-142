#include <stdio.h>
#include <math.h>


double volume_func(double r)
{
    return 4*M_PI*pow(r,3)/3;
}
double surface_square_func(double r)
{
    return 4*M_PI*pow(r,2);
}


int main()
{
    double r;

    scanf("%lf", &r);

    double volume=volume_func(r);
    double surface_square=surface_square_func(r);

    printf("\n surface_square=%lf",surface_square);
    printf("\n volume=%lf",volume);
    return 0;
}
