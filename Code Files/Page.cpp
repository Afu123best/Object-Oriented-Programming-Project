#include "Page.h"

Page::Page(string id, string name, User* owner)
: Entity(id,name)
{
    this->owner = owner;
    list_of_posts = nullptr;
    post_count = 0;
    total_likes_count = 0;
}

Page::~Page()
{
    for (int i = 0; i < post_count; i++)
    {
        delete list_of_posts[i];
    }
    delete[] list_of_posts;
}

User* Page::get_owner()
{
    return owner;
}
Post** Page::get_list_of_posts()
{
    return list_of_posts;
}
int Page::get_post_count()
{
    return post_count;
}
int Page::get_total_likes_count()
{
    return total_likes_count;
}

void Page::add_post(Post* p)
{
    Post** temp = new Post*[post_count + 1];
    for (int i = 0; i < post_count; i++)
    {
        temp[i] = list_of_posts[i];
    }
    temp[post_count] = p;
    delete[] list_of_posts;
    list_of_posts = temp;
    post_count++;
}

void Page::display()
{
    cout << id << " - " << name << endl;
}