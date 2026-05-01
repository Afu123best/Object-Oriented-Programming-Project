# Social Network Application
### OOP Project — C++

---

## Overview

A console-based social network simulation built in C++ using Object-Oriented Programming principles. The application models users, pages, posts, comments, and social interactions such as liking, commenting, and sharing memories.

---

## Project Structure

| File | Description |
|------|-------------|
| `Entity.h/.cpp` | Base class for User and Page |
| `User.h/.cpp` | Represents a user with friends, liked pages, and posts |
| `Page.h/.cpp` | Represents a page with posts and likes |
| `Post.h/.cpp` | Base class for all post types |
| `Activity.h/.cpp` | A Post with an activity type and value |
| `Memory.h/.cpp` | A Post that references an original post |
| `Comment.h/.cpp` | A comment posted by a User or Page on a Post |
| `Date.h/.cpp` | Stores and compares dates |
| `SocialNetworkApp.h/.cpp` | Main application class — loads data and handles all functionality |

---

## Data Files

The application reads from four text files at startup:

- `Users.txt` — All users, their friend lists, and liked pages
- `Pages.txt` — All pages
- `Posts.txt` — All posts (regular, activity, and memory types)
- `Comments.txt` — All comments on posts

---

## How to Run

### Compile
```bash
g++ -o app main.cpp SocialNetworkApp.cpp User.cpp Page.cpp Post.cpp Activity.cpp Memory.cpp Comment.cpp Date.cpp Entity.cpp
```

### Run
```bash
./app
```

Make sure all `.txt` data files are in the same directory as the executable.

---

## Features

| Option | Feature |
|--------|---------|
| 1 | Set System Date |
| 2 | Set Current User |
| 3 | View Home — posts from friends and liked pages within last 24 hours |
| 4 | View Profile / Timeline |
| 5 | View Friend List |
| 6 | View Liked Pages |
| 7 | Like a Post |
| 8 | View Who Liked a Post |
| 9 | Comment on a Post |
| 10 | View a Post with its Comments |
| 11 | See Your Memories — posts from same day in past years |
| 12 | Share a Memory |
| 13 | View a Page and its Posts |
| 14 | Exit |

---

## Post Types

| Type | Class | Description |
|------|-------|-------------|
| Regular | `Post` | Simple shared text post |
| Activity | `Activity` | Post with a type (feeling, thinking, making, celebrating) |
| Memory | `Memory` | Shared memory referencing an original post |

---

## Design Notes

- All arrays are dynamically allocated using double pointers (`**`)
- No global variables or functions used
- Memory is properly deallocated in destructors
- `Entity` is the base class for both `User` and `Page`, allowing polymorphic handling in likes and comments
- `Post` is the base class for `Activity` and `Memory`, with virtual `display()` for polymorphic rendering
- The `SocialNetworkApp` class acts as the application driver — `main()` only calls `app.run()`

---

## Constraints

- A post can have at most **10 likes**
- A post can have at most **10 comments**
- Home feed shows posts from the **last 24 hours** relative to the system date
