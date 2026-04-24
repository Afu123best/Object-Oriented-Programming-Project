#pragma once
#include "Entity.h"
class User;
class Post;

class Page : public Entity
{
    User* owner;
    Post** list_of_posts;
    int post_count;
    int total_likes_count;
public:
    Page(string id, string name, User* owner);
    ~Page();

    User* get_owner();
    Post** get_list_of_posts();
    int get_post_count();
    int get_total_likes_count();

    void add_post(Post* p);
    void display() override;
};