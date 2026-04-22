#pragma once
#include <string>
#include <iostream>
using namespace std;

class Entity
{
protected:
    string id;
    string name;

public:
    Entity(string i, string n) : name(n), id(i);
    string get_id();
    string get_name();
    virtual void display();
    virtual ~Entity();
};
