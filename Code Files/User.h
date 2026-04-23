#pragma once
#include "Entity.h"
class Page;
class Post;

class User : public Entity
{
    User** friends_list;
    int friend_count;
    Page** liked_pages;
    int liked_page_count;
    Post** posts;
    int post_count;
public:
    User(string id, string name);
    ~User();
    User** get_friends_list();
    Page** get_liked_pages();
    Post** get_posts();
    
    int get_friends_count();
    int get_liked_count();
    int get_post_count();

    void add_friend(User* u);
    void add_liked_page(Page* p);
    void add_post(Post* p);

    void display() override;
};