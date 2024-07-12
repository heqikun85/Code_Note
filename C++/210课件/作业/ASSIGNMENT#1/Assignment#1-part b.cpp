#include <iostream>

using namespace std;

class volum
{
public:
    double getVolume()
    {
        const double pi = 3.1415926535;
        double vol = pi * radius * radius * height;

        return vol;
    }
    void Initialize(int startR, int startH)
    {
        radius = startR;
        height = startH;
    }

private:
    int radius;
    int height;
};

int main()
{
    volum a;
    a.Initialize(10,20);
    cout << a.getVolume();
    return 0;
}
