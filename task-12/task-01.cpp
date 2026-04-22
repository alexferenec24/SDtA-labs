#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Book
{
    string title;
    string author;
    string publisher;
    string genre;
    double price{};
};

void addBook(vector<Book>& books)
{
    Book b;
    cin.ignore();

    cout << "Enter title: ";
    getline(cin, b.title);

    cout << "Enter author: ";
    getline(cin, b.author);

    cout << "Enter publisher: ";
    getline(cin, b.publisher);

    cout << "Enter genre: ";
    getline(cin, b.genre);

    cout << "Enter price: ";
    cin >> b.price;

    books.push_back(b);
    cout << "Book added.\n";
}

void deleteBook(vector<Book>& books)
{
    if (books.empty())
    {
        cout << "No books.\n";
        return;
    }

    cin.ignore();
    string name;
    cout << "Enter title of sold book: ";
    getline(cin, name);

    bool found = false;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == name)
        {
            books.erase(books.begin() + i);
            found = true;
            cout << "Book deleted.\n";
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void showBooks(const vector<Book>& books)
{
    if (books.empty())
    {
        cout << "No books.\n";
        return;
    }

    for (int i = 0; i < books.size(); i++)
    {
        cout << "\nBook " << i + 1 << ":\n";
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "Price: " << fixed << setprecision(2) << books[i].price << endl;
    }
}

void sortBooks(vector<Book>& books)
{
    int choice;
    cout << "1 - by title\n";
    cout << "2 - by author\n";
    cout << "3 - by publisher\n";
    cout << "4 - by genre\n";
    cout << "5 - by price\n";
    cout << "Choose sorting: ";
    cin >> choice;

    if (choice == 1)
    {
        ranges::sort(books, [](const Book& a, const Book& b)
        {
            return a.title < b.title;
        });
    }
    else if (choice == 2)
    {
        ranges::sort(books, [](const Book& a, const Book& b)
        {
            return a.author < b.author;
        });
    }
    else if (choice == 3)
    {
        ranges::sort(books, [](const Book& a, const Book& b)
        {
            return a.publisher < b.publisher;
        });
    }
    else if (choice == 4)
    {
        ranges::sort(books, [](const Book& a, const Book& b)
        {
            return a.genre < b.genre;
        });
    }
    else if (choice == 5)
    {
        ranges::sort(books, [](const Book& a, const Book& b)
        {
            return a.price < b.price;
        });
    }
    else
    {
        cout << "Wrong choice.\n";
        return;
    }

    cout << "Books sorted.\n";
}

void searchByGenre(const vector<Book>& books)
{
    cin.ignore();
    string genre;
    cout << "Enter genre: ";
    getline(cin, genre);

    bool found = false;

    for (const auto & book : books)
    {
        if (book.genre == genre)
        {
            cout << book.title << " | " << book.author << " | " << book.price << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchByPrice(const vector<Book>& books)
{
    double minPrice, maxPrice;
    cout << "Enter min price: ";
    cin >> minPrice;
    cout << "Enter max price: ";
    cin >> maxPrice;

    bool found = false;

    for (const auto & book : books)
    {
        if (book.price >= minPrice && book.price <= maxPrice)
        {
            cout << book.title << " | " << book.author << " | " << book.price << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchByTitle(const vector<Book>& books)
{
    cin.ignore();
    string title;
    cout << "Enter title: ";
    getline(cin, title);

    bool found = false;

    for (const auto & book : books)
    {
        if (book.title == title)
        {
            cout << book.title << " | " << book.author << " | " << book.price << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchBooks(const vector<Book>& books)
{
    int choice;
    cout << "1 - by genre\n";
    cout << "2 - by price range\n";
    cout << "3 - by title\n";
    cout << "Choose search: ";
    cin >> choice;

    if (choice == 1)
        searchByGenre(books);
    else if (choice == 2)
        searchByPrice(books);
    else if (choice == 3)
        searchByTitle(books);
    else
        cout << "Wrong choice.\n";
}

int main()
{
    vector<Book> books;
    int choice;

    do
    {
        cout << "\n1 - Add book\n";
        cout << "2 - Delete sold book\n";
        cout << "3 - Sort books\n";
        cout << "4 - Search books\n";
        cout << "5 - Show all books\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
            addBook(books);
        else if (choice == 2)
            deleteBook(books);
        else if (choice == 3)
            sortBooks(books);
        else if (choice == 4)
            searchBooks(books);
        else if (choice == 5)
            showBooks(books);
        else if (choice == 0)
            cout << "Exit.\n";
        else
            cout << "Wrong choice.\n";
    }
    while (choice != 0);

    return 0;
}