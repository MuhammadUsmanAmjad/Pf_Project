#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
// int main()
// {
//     ofstream fin;
//     for (int i = 0; i < 5; i++)
//     {
//         string str = "book";
//         str += char(i) + 48;
//         string path(getenv("HOME"));
//         path += "/Desktop/lAB_8/Books/" + str;
//         fin.open(path);
//         fin.close();
//     }
//     return 0;
///}
// int Fine; // For Fine as a Global Variable.....
// // You need to create Structs of Book and Lending. A book should have information such
// // as title, ISBN number, author, date of publishing, quantity available and total quantity in
// // the library. Lending will have information like issued Book (assign the Book Struct to
// // this), Issuing Date, Date of return, name of the person to whom the book has been
// // issued and fine applicable for late return.
struct books
{
    string auther_name;
    string book_name;
    int ISBN;
    int date_of_pub;
    int quntity_avail;
    int total_quantity_in_lib;
    books()
    {
        this->ISBN = -1;
    }
    books(string auther_name, string book_name, int ISBN, int date_of_pub, int quntity_avail, int total_quantity_in_lib)
    {
        this->auther_name = auther_name;
        this->book_name = book_name;
        this->ISBN = ISBN;
        this->total_quantity_in_lib = total_quantity_in_lib;
        this->quntity_avail = quntity_avail;
        this->date_of_pub = date_of_pub;
    }
};
struct lending
{
    books Issued_book;
    int Issuance_date;
    int date_of_return;
    string person_name;
    lending()
    {
        this->Issuance_date = -1;
    }
    lending(books Issued_book, int Issuance_date, int date_of_return, string person_name)
    {
        this->Issuance_date = Issuance_date;
        this->person_name = person_name;
        this->Issued_book = Issued_book;
    }
};
books books_Array[1000];
lending lending_array[100];
int s = 0;
bool check_status(string user_name, string pass_word, string filename)
{
    string username[100];
    string Password[100];
    ifstream fin;
    fin.open(filename);
    if (!fin)
        return false;
    int i = 0;
    while (!fin.eof())
    {
        getline(fin, username[i], ',');
        getline(fin, Password[i], '\n');
        i++;
    }
    fin.close();
    for (int j = 0; j <= i; j++)
    {
        if (username[j].compare(user_name) == 0 && Password[j].compare(pass_word))
            return true;
    }
    return false;
}
void store_in_file(string username, string password, string filename)
{
    ofstream fout;
    fout.open(filename, ios::app);
    fout << username;
    fout << ",";
    fout << password;
    fout << endl;
    fout.close();
}
void write_in_books_file(struct books obj, int i)
{
    ofstream fout;
    string str = "book";
    str += char(i) + 48;
    string path(getenv("HOME"));
    path += "/Desktop/lAB_8/Books/" + str;
    fout.open(path, ios::out);
    fout << obj.ISBN << endl;
    fout << obj.book_name << endl;
    fout << obj.auther_name << endl;
    fout << obj.date_of_pub << " ";
    fout << obj.quntity_avail << " ";
    fout << obj.total_quantity_in_lib;
    fout.close();
}
void write_in_lending_file(struct lending obj, int i)
{
    ofstream fout;
    string str = "lending";
    str += char(i) + 48;
    string path(getenv("HOME"));
    path += "/Desktop/lAB_8/Lendings/" + str;
    fout.open(path, ios::out);
    fout << obj.Issued_book.ISBN << endl;
    fout << obj.person_name << endl;
    fout << obj.Issuance_date << endl;
    fout << obj.date_of_return;
    fout.close();
}
void sort()
{
    if (s > 1)
    {
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s - 1; j++)
            {
                if (books_Array[j].ISBN > books_Array[j + 1].ISBN)
                {
                    swap(books_Array[j], books_Array[j + 1]);
                    write_in_books_file(books_Array[j], j);
                    write_in_books_file(books_Array[j + 1], j + 1);
                    swap(lending_array[j], lending_array[j + 1]);
                    write_in_lending_file(lending_array[j], j);
                    write_in_lending_file(lending_array[j + 1], j + 1);
                }
            }
        }
    }
}
void Storage()
{
    ofstream fout;
    // title, ISBN number, author, date of publishing, quantity available in the library.
    string title;
    string auther;
    int date_of_pub;
    int quantity_aval;
    int total_q;
    int isbn;
    cout << "Enter Title of the Book:-";
    getline(cin >> ws, title);
    cout << "Enter Auther of the Book:-";
    getline(cin >> ws, auther);
    cout << "Enter date of Publication:-";
    cin >> date_of_pub;
    cout << "Enter ISBN:-";
    cin >> isbn;
    cout << "Enter quantity of Book Available:-";
    cin >> quantity_aval;
    cout << "Enter total Quantity:-";
    cin >> total_q;
    books b(auther, title, isbn, date_of_pub, quantity_aval, total_q);
    books_Array[s] = b;
    string str = "book";
    str += char(s) + 48;
    string path(getenv("HOME"));
    path += "/Desktop/lAB_8/Books/" + str;
    fout.open(path, ios::out);
    fout << isbn << endl;
    fout << title << endl;
    fout << auther << endl;
    fout << date_of_pub << " ";
    fout << quantity_aval << " ";
    fout << total_q;
    fout.close();
    string st = "lending";
    st += char(s) + 48;
    string p(getenv("HOME"));
    p += "/Desktop/lAB_8/Lendings/" + st;
    fout.open(p, ios::out);
    lending_array[s].Issued_book.ISBN = books_Array[s].ISBN;
    cout << "Enter Person Name:-";
    getline(cin >> ws, lending_array[s].person_name);
    cout << "Enter Issuance Date of Book:-";
    cin >> lending_array[s].Issuance_date;
    cout << "Enter Day of  Book Return:-";
    cin >> lending_array[s].date_of_return;
    fout << lending_array[s].Issued_book.ISBN << endl;
    fout << lending_array[s].person_name << endl;
    fout << lending_array[s].Issuance_date << endl;
    fout << lending_array[s].date_of_return;
    fout.close();
    s++;
    if (s != 1)
    {
        sort();
    }
}
void menu()
{
    int choice;
    cout << "Enter 1 to Store a Book:-\n";
    cin >> choice;
    if (choice == 1)
    {
        Storage();
    }
}
int main()
{
    cout << "Enter 1 for Login and 2 for Signup:-";
    int i;
    cin >> i;
    string username;
    string password;
    if (i == 1)
    {
        cout << "Enter Username:-";
        getline(cin >> ws, username);
        cout << "Enter Password:-";
        getline(cin >> ws, password);
        bool flag = false;
        flag = check_status(username, password, "Info.txt");
        if (flag == true)
        {
            cout << "You are Successfully Loged in.\n";
            menu();
        }
        else
            cout << "Invalid Username or Password\n";
    }
    else if (i == 2)
    {
        cout << "Enter UserName:-";
        getline(cin >> ws, username);
        cout << "Enter Password:-";
        getline(cin >> ws, password);
        store_in_file(username, password, "Info.txt");
    }
    else
        cout << "Invalid\n";
    return 0;
}
