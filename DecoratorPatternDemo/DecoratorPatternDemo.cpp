#include "DecoratorPatternDemo.h"
#include <iostream>

int main()
{
    Beverage *beverage = new Espresso();
    cout << beverage->GetDecription() << " $" << beverage->Cost() << endl;

    Beverage *beverage2 = new DarkRoast();
    Mocha *mocha = new Mocha(beverage2);
    Mocha *mocha2 = new Mocha(mocha);
    Whip *whip = new Whip(mocha2);
    cout << whip->GetDecription() << " $" << whip->Cost() << endl;

    //if (beverage2 != nullptr)
    //{
    //    delete beverage2;
    //    beverage2 = nullptr;
    //}
    delete beverage2;
    delete mocha;
    delete mocha2;
    delete whip;

    system("PAUSE");

    return 0;
}