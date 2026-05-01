#include "Comment.h"

Comment::Comment(string text,Entity* posted_by)
{
    this->text = text;
    this->posted_by = posted_by;
}
Comment::~Comment(){}

string Comment::get_text()
{
    return text;
}
Entity* Comment::get_posted_by()
{
    return posted_by;
}

void Comment::display()
{
    cout << posted_by->get_name() << " wrote: \"" << text << "\"" << endl;
}