#include "ObserverPatternDemo.h"

int main()
{
    InstanceSubject *insSubject = new InstanceSubject;
    Observer *ob1 = new SubObserver(1);
    Observer *ob2 = new SubObserver(2);

    insSubject->RegisterObservers(ob1);
    insSubject->RegisterObservers(ob2);

    insSubject->NotifyObservers();

    delete insSubject;
    delete ob1;
    delete ob2;

    system("PAUSE");

    return 0;
}