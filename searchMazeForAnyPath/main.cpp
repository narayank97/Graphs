#include <iostream>
#include "coordinate.h"

using namespace std;

int main(){
    coordinate point1 = coordinate(1,1);
    coordinate point2 = coordinate(1,1);
    coordinate point3 = coordinate(5,5);

    point1.printCoord();
    point3.printCoord();

    cout << point1.isEqualTo(point2) << endl;
    cout << point1.isEqualTo(point3) << endl;

    return 0;
}
