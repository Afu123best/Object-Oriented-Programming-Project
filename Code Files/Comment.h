#pragma once
#include <string>
#include "Entity.h"

class Comment
{
    string text;
    Entity* posted_by;
public:
    Comment(string text,Entity* posted_by);
    ~Comment();

    string get_text();
    Entity* get_posted_by();

    void display();
};