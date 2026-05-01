#include "Memory.h"
#include "Post.h"

Memory::Memory(string id, string description, Date* d, Entity* posted_by, Post* original_post)
: Post(id, description, d, posted_by)
{
    this->original_post = original_post;
}

Post* Memory::get_original_post()
{
    return original_post;
}

void Memory::display()
{
    cout << "~~~ " << get_posted_by()->get_name() << " shared a memory ~~~ ...(";
    get_shared_date()->display();
    cout << ")" << endl;
    cout << "\"" << get_description() << "\"" << endl;
    int years_ago = get_shared_date()->get_year() - original_post->get_shared_date()->get_year();
    cout << "(" << years_ago << " Years Ago)" << endl;
    original_post->display_no_comments();
    display_comments();
}
