#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include "Entity.h"
#include "Comment.h"
using namespace std;

class Post
{
    string id;
    string description;
    Date* shared_date;

    Entity* list_of_likes[10];
    int likes_count;
    
    Comment* list_of_comments[10];
    int comments_count;

    Entity* posted_by;
public:
    Post(string id, string description, Date* d, Entity* posted_by);
    ~Post();

    string get_id();
    string get_description();
    Date* get_shared_date();
    int get_likes_count();
    int get_comments_count();
    Entity** get_list_of_likes();
    Entity* get_posted_by();

    void add_like(Entity* e);
    void add_comment(Comment* c);

    void display_comments();
    virtual void display();
};