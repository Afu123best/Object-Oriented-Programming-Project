#include "Post.h"

Post::Post(string id, string description, Date* d, Entity* posted_by)
{
    this->id = id;
    this->description = description;
    this->shared_date = d;
    likes_count = 0;
    comments_count = 0;
    for (int i = 0; i < 10; i++)
    {
        list_of_likes[i] = nullptr;
        list_of_comments[i] = nullptr;
    }
    this->posted_by = posted_by;
}
Post::~Post()
{
    delete shared_date;
    for (int i = 0; i < comments_count; i++)
    {
        delete list_of_comments[i];
    }
}

string Post::get_id()
{
    return id;
}
string Post::get_description()
{
    return description;
}
Date* Post::get_shared_date()
{
    return shared_date;
}
int Post::get_likes_count()
{
    return likes_count;
}
int Post::get_comments_count()
{
    return comments_count;
}
Entity** Post::get_list_of_likes()
{
    return list_of_likes;
}
Entity* Post::get_posted_by()
{
    return posted_by;
}

void Post::add_like(Entity* e)
{
    if (likes_count < 10)
    {
        list_of_likes[likes_count] = e;
        likes_count++;
    }
}

void Post::add_comment(Comment* c)
{
    if (comments_count < 10)
    {
        list_of_comments[comments_count] = c;
        comments_count++;
    }
}

void Post::display_comments()
{
    for (int i = 0;i < comments_count; i++)
    {
        list_of_comments[i]->display();
    }
}

void Post::display()
{
    cout << "--- " << posted_by->get_name() << " shared \"" << description << "\"" << endl;
    display_comments();
}

void Post::display_no_comments()
{
    cout << "--- " << posted_by->get_name() << " shared \"" << description << "\"" << endl;
}
