#include "User.h"

User::User(string id, string name)
: Entity(id,name)
{
    friends_list = nullptr;
    liked_pages = nullptr;
    posts = nullptr;
    friend_count = 0;
    liked_page_count = 0;
    post_count = 0;
}
User::~User()
{
    delete[] friends_list;

    delete[] liked_pages;

    for (int i = 0; i < post_count; i++)
    {
        delete posts[i];
    }
    delete[] posts;
}

User** User::get_friends_list()
{
    return friends_list;
}
Page** User::get_liked_pages()
{
    return liked_pages;
}
Post** User::get_posts()
{
    return posts;
}

int User::get_friends_count()
{
    return friend_count;
}
int User::get_liked_count()
{
    return liked_page_count;
}
int User::get_post_count()
{
    return post_count;
}

void User::add_friend(User* u)
{
    User** temp = new User*[friend_count+1];
    for (int i = 0; i < friend_count; i++)
    {
        temp[i] = friends_list[i];
    }
    temp[friend_count] = u;
    delete[] friends_list;
    friends_list = temp;
    friend_count++;
}

void User::add_liked_page(Page* p)
{
    Page** temp = new Page*[liked_page_count + 1];
    for (int i = 0; i < liked_page_count; i++)
    {
        temp[i] = liked_pages[i];
    }
    temp[liked_page_count] = p;
    delete[] liked_pages;
    liked_pages = temp;
    liked_page_count++;
}

void User::add_post(Post* p)
{
    Post** temp = new Post*[post_count + 1];
    for (int i = 0; i < post_count; i++)
    {
        temp[i] = posts[i];
    }
    temp[post_count] = p;
    delete[] posts;
    posts = temp;
    post_count++; 
}

void User::display()
{
    cout << id << " - " << name << endl;
}