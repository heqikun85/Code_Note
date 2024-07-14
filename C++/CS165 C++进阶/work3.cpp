#include <iostream>
#include <cmath>

using namespace std;

bool isValid(double, double, double);
double area (double, double, double);

bool isValid(double s1, double s2, double s3)
{
  double sum1, sum2, sum3;

  sum1=s1+s2;
  sum2=s1+s3;
  sum3=s2+s3;
  if(sum1>s3 || sum2>s2 || sum3>s1){
     return true;
  }

}

double area (double s1, double s2, double s3)
{
    double s, a;

    cout << "Please enter the three sides info. : ";
    cin >> s1 >> s2 >> s3;

    if(isValid(s1,s2,s3)== true){
        s = (s1+s2+s3)/2;
        a = pow(s*(s-s1)*(s-s2)*(s-s3) , 1.0/3);
        return a;
    }
    else
        cout << "input is invalid"<<endl;

}

int main()
{
    double a, b, c;
    cout << "the triangle's area is "<< area(a, b, c);

}
