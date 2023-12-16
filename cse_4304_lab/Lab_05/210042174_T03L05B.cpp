#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateArea(double XY, double XZ, double YZ, double XL)
{
    double s = (XY + YZ + XZ) / 2.0;
    return sqrt(s * (s - XY) * (s - YZ) * (s - XZ));
}

double findXL(double XY, double XZ, double YZ, double desired_ratio)
{
    double low = 0, high = XY, mid, area, lowArea, highArea, ratio, precision = 0.0000001;

    {
        while ((high - low) >= precision)

        {
            mid = (low + high) / 2.0;
            lowArea = calculateArea(XY, XZ, YZ, low);
            highArea = calculateArea(XY, XZ, YZ, high);

            area = calculateArea(XY, XZ, YZ, mid);
            cout << area << endl;
            cout << mid << endl;
            ratio = area / calculateArea(XY, XZ, YZ, XY);

            if (ratio > desired_ratio)
                high = mid;
            else
                low = mid;
        }
        return low;
    }
}

int main()
{
    int testCases;
    cin >> testCases;

    for (int caseNum = 1; caseNum <= testCases; ++caseNum)
    {
        double XY, XZ, YZ, ratio;
        cin >> XY >> XZ >> YZ >> ratio;

        double XL = findXL(XY, XZ, YZ, ratio);
        cout << "Case " << caseNum << ": " << fixed << setprecision(6) << XL << endl;
    }

    return 0;
}
