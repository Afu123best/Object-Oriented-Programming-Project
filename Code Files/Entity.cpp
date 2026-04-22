#include "Entity.h"
#include <string>
#include <iostream>
using namespace std;


Entity::Entity(string i, string n)
: id(i), name(n)
{}
string Entity::get_id()
{
    return id;
}
string Entity::get_name()
{
    return name;
}
void Entity::display()
{
    cout << "ID: " << id << " Name: " << name << endl;
}
Entity::~Entity(){};

