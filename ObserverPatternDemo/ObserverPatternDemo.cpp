#include "ObserverPatternDemo.h"

int main()
{
    InstanceSubject *insSubject = new InstanceSubject;
    Observer *ob1 = new Observer1;
    Observer *ob2 = new Observer2;

    insSubject->RegisterObservers(ob1);
    insSubject->RegisterObservers(ob2);

    insSubject->NotifyObservers();

    delete insSubject;
    delete ob1;
    delete ob2;

    system("PAUSE");

    return 0;
}