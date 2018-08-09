#pragma once

#include <string>

using namespace std;

class Beverage
{
public:
    Beverage() {}
    virtual ~Beverage() {}
    string m_description = "Unknown Beverage";
    virtual string GetDecription() { return m_description; }
    virtual double Cost() { return 0; }
};

class CondimentDecorator : public Beverage
{
public:
    virtual string GetDecription() = 0;
};

class Espresso : public Beverage
{
public:
    Espresso() { m_description = "Espresso"; }
    double Cost() { return 1.99; }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend() { m_description = "House Blend Coffee"; }
    double Cost() { return 0.89; }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast() { m_description = "Dark Roast Coffee"; }
    double Cost() { return 0.99; }
};

class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *beverage):m_beverage(beverage) {}
    string GetDecription() { return m_beverage->GetDecription() + ", Mocha"; }
    double Cost() { return  0.20 + m_beverage->Cost(); }
private:
    Beverage *m_beverage;
};

class Whip : public CondimentDecorator
{
public:
    Whip(Beverage *beverage) :m_beverage(beverage) {}
    string GetDecription() { return m_beverage->GetDecription() + ", Whip"; }
    double Cost() { return  0.10 + m_beverage->Cost(); }
private:
    Beverage *m_beverage;
};

class Soy : public CondimentDecorator
{
public:
    Soy(Beverage *beverage) :m_beverage(beverage) {}
    string GetDecription() { return m_beverage->GetDecription() + ", Soy"; }
    double Cost() { return  0.15 + m_beverage->Cost(); }
private:
    Beverage *m_beverage;
};