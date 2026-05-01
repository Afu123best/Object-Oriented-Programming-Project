#pragma once
#include "Post.h"
#include <string>
#include <iostream>
using namespace std;

class Activity : public Post
{
    int type;
    string value;
public:
    Activity(string id, string description, Date* d, Entity* posted_by,int type, string value);

    int get_type();
    string get_value();
    
    void display() override;
    void display_no_comments();
};
