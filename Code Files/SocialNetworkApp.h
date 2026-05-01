#pragma once
#include "User.h"
#include "Page.h"
#include "Entity.h"
#include "Post.h"
#include "Activity.h"
#include "Memory.h"
#include "Comment.h"
#include "Date.h"
#include <fstream>

class SocialNetworkApp
{
    User **all_users;
    Page **all_pages;
    Post **all_posts;
    User *current_user;
    Date *system_date;

    int user_count;
    int page_count;
    int post_count;

public:
    SocialNetworkApp();
    ~SocialNetworkApp();

    User* find_user(string id);
    Page* find_page(string id);
    Post* find_post(string id);

    void load_users();
    void load_pages();
    void load_posts();
    void load_relationships();
    void load_data();

    void run();

    void set_system_date();

    void set_current_user();

    void view_home();

    void view_profile();

    void view_friend_list();

    void view_liked_pages();

    void like_post();

    void view_liked_list();

    void comment_on_post();

    void view_post();

    void see_your_memories();

    void share_memory();

    void view_page();
};
