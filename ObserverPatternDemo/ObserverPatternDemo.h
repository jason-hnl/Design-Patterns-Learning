#pragma once

#include <list>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() = 0;
};

class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}
    virtual void RegisterObservers(Observer *ob) = 0;
    virtual void RemoveObservers(Observer *ob) = 0;
    virtual void NotifyObservers() = 0;

//    virtual void SetDataChanged(string status, int value) = 0;
//    virtual string GetStatus() = 0;
//    virtual int GetValue()
//
//private:
//    list<Observer *> m_observers;
//
//protected:
//    string m_status;
//    int m_value;
};

class InstanceSubject : public Subject
{
public:
    InstanceSubject() {}
    virtual ~InstanceSubject() {}
    virtual void RegisterObservers(Observer *ob) { m_observers.push_back(ob); }
    virtual void RemoveObservers(Observer *ob) { m_observers.remove(ob); delete ob; }
    virtual void NotifyObservers()
    {
        for_each(m_observers.begin(), m_observers.end(), [&](Observer *ob) {
            ob->Update();
        });
    }

//    virtual void SetDataChanged(int value) { m_value = value; }
//    virtual int GetValue() { return m_value; }
//
//protected:
//    int m_value;

private:
    list<Observer *> m_observers;
};


class Observer1 : public Observer
{
public:
    Observer1() {}
    ~Observer1() {}
    virtual void Update() { cout << "Current Observer is 1" << endl; }
};

class Observer2 : public Observer
{
public:
    Observer2() {}
    ~Observer2() {}
    virtual void Update() { cout << "Current Observer is 2" << endl; }
};