#include <stdio.h>
#include <math.h>


double afunc(double x, double y, double z)
{
    return (2*pow(z,x))/(sqrt((pow(y,x)*pow(cos(x+y),2)))-3*z);
}

double bfunc(double x, double y, double z)
{
    return x*exp(sqrt(z))*cos((pow(x,2))/(y*z));
}

int main()
{
    const double x=0.78;
    const double y=1.24;
    const double z=0.5;
    double a=afunc(x,y,z);
    double b=bfunc(x,y,z);

    printf("a=%f\n",a);
    printf("b=%f\n",b);

    return 0;
}