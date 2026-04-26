#include "SocialNetworkApp.h"

SocialNetworkApp::SocialNetworkApp()
{
    all_users = nullptr;
    all_pages = nullptr;
    all_posts = nullptr;
    current_user = nullptr;
    system_date = nullptr;

    user_count = 0;
    page_count = 0;
    post_count = 0;
}
SocialNetworkApp::~SocialNetworkApp()
{
    for (int i = 0; i < user_count; i++)
    {
        delete all_users[i];
    }
    delete[] all_users;

    for (int i = 0; i < page_count; i++)
    {
        delete all_pages[i];
    }
    delete[] all_pages;

    for (int i = 0; i < post_count; i++)
    {
        delete all_posts[i];
    }
    delete[] all_posts;

    delete system_date;
}

void SocialNetworkApp::load_data()
{
    //USERS
    user_count = 20;
    all_users = new User*[user_count];
    all_users[0] =  new User("u1", "Amna Akram");
    all_users[1] =  new User("u2", "Muhammad Ali");
    all_users[2] =  new User("u3", "Waheed Khan");
    all_users[3] =  new User("u4", "Burhan Tahir");
    all_users[4] =  new User("u5", "Hassan Sohail");
    all_users[5] =  new User("u6", "Saad Ali");
    all_users[6] =  new User("u7", "Abdullah Nadeem");
    all_users[7] =  new User("u8", "Nimra Batool");
    all_users[8] =  new User("u9", "Abubakar Javed");
    all_users[9] =  new User("u10", "Saad Sultan");
    all_users[10] =  new User("u11", "Ahsan Ali");
    all_users[11] =  new User("u12", "Ali Ahmed");
    all_users[12] =  new User("u13", "Saad Ahmed");
    all_users[13] =  new User("u14", "Usman Usman");
    all_users[14] =  new User("u15", "Zaid Tariq");
    all_users[15] =  new User("u16", "Abdullah Siddiqui");
    all_users[16] =  new User("u17", "Saif ullah");
    all_users[17] =  new User("u18", "Hashir Baig");
    all_users[18] =  new User("u19", "Usama  Jawad");
    all_users[19] =  new User("u20", "Haris Muneer");

    //Pages
    page_count = 12;
    all_pages = new Page*[page_count];
    all_pages[0] = new Page("p1", "Food Fusion", nullptr);
    all_pages[1] = new Page("p2", "Al Jazeera English", nullptr);
    all_pages[2] = new Page("p3", "Allama Iqbal", nullptr);
    all_pages[3] = new Page("p4", "Scholarships for International Students", nullptr);
    all_pages[4] = new Page("p5", "Rumi Quotes", nullptr);
    all_pages[5] = new Page("p6", "Dawn.com", nullptr);
    all_pages[6] = new Page("p7", "People Of Pakistan", nullptr);
    all_pages[7] = new Page("p8", "History", nullptr);
    all_pages[8] = new Page("p9", "BBC News", nullptr);
    all_pages[9] = new Page("p10", "CNN International", nullptr);
    all_pages[10] = new Page("p11", "Birthday Cakes", nullptr);
    all_pages[11] = new Page("p12", "M Ali Jinnah", nullptr);

    //Posts
    post_count = 12;
    all_posts = new Post*[post_count];
    all_posts[0] = new Activity("post1", "OOP Project Started Yayy....", new Date(14,11,2017), all_users[2], 1, "excited");
    all_posts[1] = new Activity("post2", "Life will be beautiful after exams", new Date(13,11,2017), all_users[2], 2, "Mids");
    all_posts[2] = new Post("post3", "Waiting for Weekend", new Date(14,11,2017), all_users[10]);
    all_posts[3] = new Post("post4", "Waiting for Result", new Date(14,11,2017), all_users[11]);
    all_posts[4] = new Activity("post5", "Try this at home...", new Date(14,11,2017), all_pages[0], 3, "Kashmiri Chai (Pink Tea)");
    all_posts[5] = new Post("post6", "Oil drilling in Alaska's indigenous communities is on the table again.", new Date(14,11,2017), all_pages[1]);
    all_posts[6] = new Post("post7", "Be free of possessing things - Rumi", new Date(15,11,2017), all_pages[4]);
    all_posts[7] = new Activity("post8", "Happy Birthday to my dear Mom", new Date(14,11,2017), all_users[6], 4, "a birthday");
    all_posts[8] = new Activity("post9", "Happy Birthday to my dear Father", new Date(14,10,2017), all_users[6], 4, "a birthday");
    all_posts[9] = new Activity("post10", "Got D in toughest subject... Thanks God I am Pass finally...", new Date(15,11,2015), all_users[6], 4, "Success");
    all_posts[10] = new Activity("post11", "Sunday Special Breafast for our followers...", new Date(10,11,2017) ,all_pages[0], 3, "Halwa Puri");
    all_posts[11] = new Activity("post12", "Happy Birthday Ali Bhai", new Date(10,10,2017), all_users[19], 4, "a birthday");

    //Friendships
    all_users[0]->add_friend(all_users[1]);
    all_users[0]->add_friend(all_users[2]);
    all_users[0]->add_friend(all_users[3]);
    all_users[0]->add_liked_page(all_pages[0]);
    all_users[0]->add_liked_page(all_pages[1]);

    all_users[1]->add_friend(all_users[0]);
    all_users[1]->add_friend(all_users[4]);
    all_users[1]->add_friend(all_users[5]);
    all_users[1]->add_liked_page(all_pages[1]);
    all_users[1]->add_liked_page(all_pages[2]);

    all_users[2]->add_friend(all_users[0]);
    all_users[2]->add_friend(all_users[6]);

    all_users[3]->add_friend(all_users[0]);
    all_users[3]->add_friend(all_users[7]);
    all_users[3]->add_friend(all_users[8]);
    all_users[3]->add_friend(all_users[9]);
    all_users[3]->add_liked_page(all_pages[9]);

    all_users[4]->add_friend(all_users[1]);
    all_users[4]->add_liked_page(all_pages[8]);
    all_users[4]->add_liked_page(all_pages[9]);

    all_users[5]->add_friend(all_users[1]);
    all_users[5]->add_friend(all_users[10]);
    all_users[5]->add_liked_page(all_pages[7]);

    all_users[6]->add_friend(all_users[2]);
    all_users[6]->add_friend(all_users[10]);
    all_users[6]->add_friend(all_users[11]);
    all_users[6]->add_liked_page(all_pages[0]);
    all_users[6]->add_liked_page(all_pages[1]);
    all_users[6]->add_liked_page(all_pages[4]);
    all_users[6]->add_liked_page(all_pages[8]);

    all_users[7]->add_friend(all_users[3]);
    all_users[7]->add_friend(all_users[10]);

    all_users[8]->add_friend(all_users[3]);
    all_users[8]->add_liked_page(all_pages[3]);

    all_users[9]->add_friend(all_users[3]);
    all_users[9]->add_friend(all_users[11]);
    all_users[9]->add_liked_page(all_pages[1]);

    all_users[10]->add_friend(all_users[5]);
    all_users[10]->add_friend(all_users[6]);
    all_users[10]->add_friend(all_users[7]);
    all_users[10]->add_liked_page(all_pages[0]);

    all_users[11]->add_friend(all_users[6]);
    all_users[11]->add_friend(all_users[9]);
    all_users[11]->add_liked_page(all_pages[4]);

    all_users[12]->add_friend(all_users[13]);
    all_users[12]->add_friend(all_users[14]);
    all_users[12]->add_liked_page(all_pages[2]);

    all_users[13]->add_friend(all_users[12]);
    all_users[13]->add_friend(all_users[15]);
    all_users[13]->add_liked_page(all_pages[1]);

    all_users[14]->add_friend(all_users[12]);
    all_users[14]->add_friend(all_users[15]);
    all_users[14]->add_liked_page(all_pages[0]);

    all_users[15]->add_friend(all_users[13]);
    all_users[15]->add_friend(all_users[14]);
    all_users[15]->add_friend(all_users[16]);
    all_users[15]->add_liked_page(all_pages[0]);

    all_users[16]->add_friend(all_users[15]);
    all_users[16]->add_liked_page(all_pages[0]);

    all_users[17]->add_friend(all_users[18]);

    all_users[18]->add_friend(all_users[17]);
    all_users[18]->add_liked_page(all_pages[6]);

    //posts to users/pages
    all_users[2]->add_post(all_posts[0]);
    all_users[2]->add_post(all_posts[1]);
    all_users[10]->add_post(all_posts[2]);
    all_users[11]->add_post(all_posts[3]);
    all_pages[0]->add_post(all_posts[4]);
    all_pages[1]->add_post(all_posts[5]);
    all_pages[4]->add_post(all_posts[6]);
    all_users[6]->add_post(all_posts[7]);
    all_users[6]->add_post(all_posts[8]);
    all_users[6]->add_post(all_posts[9]);
    all_pages[0]->add_post(all_posts[10]);
    all_users[19]->add_post(all_posts[11]);

    //likes to posts
    all_posts[0]->add_like(all_users[0]);

    all_posts[1]->add_like(all_users[6]);

    all_posts[2]->add_like(all_users[5]);
    all_posts[2]->add_like(all_users[6]);

    

    all_posts[4]->add_like(all_users[1]);
    all_posts[4]->add_like(all_pages[0]);
    all_posts[4]->add_like(all_users[2]);
    all_posts[4]->add_like(all_users[3]);

    

    all_posts[6]->add_like(all_users[6]);
    all_posts[6]->add_like(all_pages[4]);

    all_posts[7]->add_like(all_users[1]);
    all_posts[7]->add_like(all_users[2]);
    all_posts[7]->add_like(all_users[3]);

    all_posts[8]->add_like(all_users[1]);
    all_posts[8]->add_like(all_users[3]);

    all_posts[9]->add_like(all_users[1]);
    all_posts[9]->add_like(all_users[3]);

    all_posts[10]->add_like(all_pages[0]);

    //comments
    all_posts[0]->add_comment(new Comment("Best of Luck", all_users[0]));
    all_posts[0]->add_comment(new Comment("Interesting", all_users[6]));

    all_posts[2]->add_comment(new Comment("Any plans for Get Together?", all_users[5]));
    all_posts[2]->add_comment(new Comment("Yes BBQ", all_users[6]));
    all_posts[2]->add_comment(new Comment("Lunch Buffet please", all_users[7]));

    all_posts[4]->add_comment(new Comment("Followers please try this recipe and give your feedback", all_pages[0]));
    all_posts[4]->add_comment(new Comment("Yummy", all_users[0]));
    all_posts[4]->add_comment(new Comment("One pink tea for me", all_users[10]));

    all_posts[6]->add_comment(new Comment("Rumi is great", all_users[11]));

    all_posts[7]->add_comment(new Comment("Happy Birthday Aunty", all_users[2]));

    all_posts[8]->add_comment(new Comment("Happy Birthday Uncle", all_users[10]));

    all_posts[3]->add_comment(new Comment("Good Luck for your Result", all_users[6]));

    all_posts[9]->add_comment(new Comment("Celebrations???", all_users[10]));
}

void SocialNetworkApp::run()
{
    load_data();
    int choice;
    cout << "1.Set System Date\n2.Set Current User\n3.View Home\n4.View Profile\n5.View Friend List\n6.View Liked Pages\n7.Like Post\n8.View Liked List\n9.Comment On Post\n10.View Post\n11.See Your Memories\n12.Share Memory\n13.View Page\n14.Exit";
    while (true)
    {
        cout << "\nEnter command: ";
        cin >> choice;
        if (choice == 1)
        {
            set_system_date();
        }
        else if (choice == 2)
        {
            set_current_user();
        }
        else if (choice == 3)
        {
            view_home();
        }
        else if (choice == 4)
        {
            view_profile();
        }
        else if (choice ==  5)
        {
            view_friend_list();
        }
        else if (choice == 6)
        {
            view_liked_pages();
        }
        else if (choice == 7)
        {
            like_post();
        }
        else if (choice == 8)
        {
            view_liked_list();
        }
        else if (choice == 9)
        {
            comment_on_post();
        }
        else if (choice == 10)
        {
            view_post(); 
        }
        else if (choice == 11)
        {
            see_your_memories();
        }
        else if (choice == 12)
        {
            share_memory();
        }
        else if (choice == 13)
        {
            view_page();
        }
        else if (choice == 14)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Retry!";
        }
    }
}

void SocialNetworkApp::set_system_date()
{
    int day, month, year;
    if (system_date != nullptr)
    {
        delete system_date;
    }
    cout << "Enter system day: ";
    cin >> day;
    cout << endl;
    cout << "Enter system month: ";
    cin >> month;
    cout << endl;
    cout << "Enter system year: ";
    cin >> year;
    system_date = new Date(day,month,year);
    cout << "System Date set as: " << system_date->get_day() << "/" << system_date->get_month() << "/" << system_date->get_year() << endl;
}

void SocialNetworkApp::set_current_user()
{
    string user_id;
    cout << "Enter user ID: ";
    cin >> user_id;
    for (int i = 0; i < user_count; i++)
    {
        if (all_users[i]->get_id() == user_id)
        {
            current_user = all_users[i];
            cout << current_user->get_name() << " successfully set as Current User";
            return;
        }
    }
    cout << "User not found.\n";
}

void SocialNetworkApp::view_home()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << current_user->get_name() << " - View Home" << endl; 
    //friends' post
    User** friends = current_user->get_friends_list();
    for (int i = 0; i < current_user->get_friends_count(); i++)
    {
        Post** posts = friends[i]->get_posts();
        for (int j = 0; j < friends[i]->get_post_count(); j++)
        {
            if (posts[j]->get_shared_date()->is_within_24_hrs(*system_date))
            {
                posts[j]->display();
            }
        }
    }

    //liked pages' posts
    Page** liked_pages = current_user->get_liked_pages();
    for (int i = 0; i < current_user->get_liked_count(); i++)
    {
        Post** posts = liked_pages[i]->get_list_of_posts();
        for (int j = 0; j < liked_pages[i]->get_post_count(); j++)
        {
            if (posts[j]->get_shared_date()->is_within_24_hrs(*system_date))
            {
                posts[j]->display();
            }
        }
    }
}

void SocialNetworkApp::view_profile()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << current_user->get_name() << " - Time Line" << endl;
    Post** posts = current_user->get_posts();
    for (int i = 0; i < current_user->get_post_count(); i++)
    {
        posts[i]->display();
    }
}

void SocialNetworkApp::view_friend_list()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << current_user->get_name() << " - Friend List" << endl;
    User** friends = current_user->get_friends_list();
    for (int i = 0; i < current_user->get_friends_count(); i++)
    {
        cout << friends[i]->get_id() << " - " << friends[i]->get_name() << endl;
    }
}

void SocialNetworkApp::view_liked_pages()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << current_user->get_name() << " - Liked Pages" << endl;
    Page** pages = current_user->get_liked_pages();
    for (int i = 0; i < current_user->get_liked_count(); i++)
    {
        cout << pages[i]->get_id() << " - " << pages[i]->get_name() << endl;
    }
}

void SocialNetworkApp::like_post()
{
    if (current_user == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    string post_id;
    cout << "Enter post ID: ";
    cin >> post_id;
    for (int i = 0; i < post_count; i++)
    {
        if (all_posts[i]->get_id() == post_id)
        {
            all_posts[i]->add_like(current_user);
            cout << "Post liked successfully." << endl;
            return;
        }
    }
    cout << "Post not found." << endl;
}

void SocialNetworkApp::view_liked_list()
{
    if (current_user == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    string post_id;
    cout << "Enter post ID:";
    cin >> post_id;
    for (int i = 0; i < post_count; i++)
    {
        if (all_posts[i]->get_id() == post_id)
        {
            cout << "Post Liked By:\n";
            Entity** likes = all_posts[i]->get_list_of_likes();
            for (int j = 0; j < all_posts[i]->get_likes_count(); j++)
            {
                likes[j]->display();
            }
            return;
        }
    }
    cout << "Post not found." << endl;
}

void SocialNetworkApp::comment_on_post()
{
    if (current_user == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << "Enter post ID to comment on: ";
    string post_id;
    cin >> post_id;
    cout << "Enter your comment: ";
    string comment;
    cin.ignore();
    getline(cin, comment);
    for (int i = 0; i < post_count; i++)
    {
        if (all_posts[i]->get_id() == post_id)
        {
            all_posts[i]->add_comment(new Comment(comment,current_user));
            cout << "Comment successfully added\n";
            return;
        }
    }
    cout << "Post not found\n";
}

void SocialNetworkApp::view_post()
{
    if (current_user == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << "Enter post ID to view: ";
    string post_id;
    cin >> post_id;
    for (int i = 0; i < post_count; i++)
    {
        if (all_posts[i]->get_id() == post_id)
        {
            all_posts[i]->display();
            return;
        }
    }
    cout << "Post not found\n";
}

void SocialNetworkApp::see_your_memories()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << "We hope you enjoy looking back and sharing your memories, from the most recent to those long ago.\nOn this Day\n";
    Post** posts = current_user->get_posts();
    for (int i = 0; i < current_user->get_post_count(); i++)
    {
        Date* d = posts[i]->get_shared_date();
        if (d->get_day() == system_date->get_day() && d->get_month() == system_date->get_month() && d->get_year() < system_date->get_year())
        {
            int years_ago = system_date->get_year() - d->get_year();
            cout << years_ago << " Years Ago" << endl;
            posts[i]->display();
        }
    }
}

void SocialNetworkApp::share_memory()
{
    if (current_user == nullptr || system_date == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << "Enter post ID to share memory on: ";
    string post_id;
    cin >> post_id;
    cout << "Enter new text: ";
    string new_text;
    cin.ignore();
    getline(cin, new_text);
    Post** posts = current_user->get_posts();
    for (int i = 0; i < post_count; i++)
    {
        if (all_posts[i]->get_id() == post_id)
        {
            string mem_id = "mem" + to_string(current_user->get_post_count() + 1);
            Memory* m = new Memory(mem_id, new_text, new Date(system_date->get_day(), system_date->get_month(), system_date->get_year()), current_user, all_posts[i]);
            current_user->add_post(m);
            cout << "Memory shared successfully" << endl;
            return;
        }
    }
    cout << "Post not found";
}

void SocialNetworkApp::view_page()
{
    if (current_user == nullptr)
    {
        cout << "Please set current user first." << endl;
        return;
    }
    cout << "Enter page ID to view: ";
    string page_id;
    cin >> page_id;
    for (int i = 0; i < page_count; i++)
    {
        if (all_pages[i]->get_id() == page_id)
        {
            cout << all_pages[i]->get_name() << endl;
            Post** posts = all_pages[i]->get_list_of_posts();
            for (int j = 0; j < all_pages[i]->get_post_count(); j++)
            {
               posts[j]->display();
            }
            return;
        }
    }
    cout << "Page not found\n";
}

