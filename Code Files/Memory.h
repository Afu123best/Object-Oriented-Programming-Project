#pragma once
#include "Post.h"

class Memory : public Post
{
    Post* original_post;
public:
    Memory(string id, string description, Date* d, Entity* posted_by, Post* original_post);

    Post* get_original_post();

    void display() override;
};