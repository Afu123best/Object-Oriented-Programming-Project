#include "Activity.h"
#include "Post.h"

Activity::Activity(string id, string description, Date* d, Entity* posted_by, int type, string value)
: Post(id, description, d, posted_by)
{
    this->type = type;
    this->value = value;
}

int Activity::get_type()
{
    return type;
}
string Activity::get_value()
{
    return value;
}

void Activity::display()
{
    cout << "--- " << get_posted_by()->get_name() << " is ";
    if (type == 1)
    {
        cout << "feeling " << value << endl;
    }
    else if (type == 2)
    {
        cout << "thinking about " << value << endl;
    }
    else if (type == 3)
    {
        cout << "making " << value << endl;
    }
    else if (type == 4)
    {
        cout << "celebrating " << value << endl; 
    }
    cout << "\"" << get_description() << "\" ... (";
    get_shared_date()->display();
    cout << ")" << endl;
    display_comments();
}

void Activity::display_no_comments()
{
    cout << "--- " << get_posted_by()->get_name() << " is ";
    if (type == 1) cout << "feeling " << value << endl;
    else if (type == 2) cout << "thinking about " << value << endl;
    else if (type == 3) cout << "making " << value << endl;
    else if (type == 4) cout << "celebrating " << value << endl;
    cout << "\"" << get_description() << "\" ... (";
    get_shared_date()->display();
    cout << ")" << endl;
}
