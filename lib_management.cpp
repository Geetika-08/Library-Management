#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Library {
public:
    int id;
    string name;
    string student;
    string author;
    int price;
    int pages;

    void inputDetails() {
        cout << "Enter Book Id: ";
        cin >> id;
        cin.ignore(); // Ignore the newline character left in the input buffer

        cout << "Enter Book Name: ";
        getline(cin, name);

        cout << "Enter Book Author: ";
        getline(cin, author);

        cout << "Enter Student Name: ";
        getline(cin, student);

        cout << "Enter Book Price: ";
        cin >> price;
        cin.ignore();
    }

    void displayDetails() const {
        cout << "Book Id: " << id << '\n'
             << "Book Name: " << name << '\n'
             << "Author Name: " << author << '\n'
             << "Student Name: " << student << '\n'
             << "Book Price: " << price << '\n';
    }
};

void displayMenu() {
    cout << "Enter 1 to input details like id, name, author, student, etc.\n"
         << "Enter 2 to display details\n"
         << "Enter 3 to search a book by id\n"
         << "Enter 4 to update details of a book by id\n"
         << "Enter 5 to delete a book by id\n"
         << "Enter 6 to quit\n";
}

bool setPassword(string &password) {
    string password1, password2;

    cout <<"-------Welcome to our library-------\n" << "Please Set Your Password: ";
    cin >> password1;

    cout << "Confirm your password: ";
    cin >> password2;

    if (password1 == password2) {
        password = password1;
        return true;
    } else {
        cout << "Passwords do not match! Try again.\n";
        return false;
    }
}

bool checkPassword(const string &password) {
    string inputPassword;

    cout << "Enter password to proceed: ";
    cin >> inputPassword;

    return inputPassword == password;
}

void inputBookDetails(vector<Library>& lib) {
    Library book;
    book.inputDetails();
    lib.push_back(book);
}

void displayBookDetails(const vector<Library>& lib) {
    for (vector<Library>::const_iterator it = lib.begin(); it != lib.end(); ++it) {
        it->displayDetails();
        cout << '\n';
    }
}

void searchBook(const vector<Library>& lib){
    int searchId;
    cout << "Enter the book Id to search: ";
    cin >> searchId;

    for (vector<Library>::const_iterator it = lib.begin(); it != lib.end(); ++it) {
        if (it->id == searchId) {
            it->displayDetails();
            return;
        }
    }

    cout << "Book not found.\n";
}

void updateBook(vector<Library>& lib){
    int updateId;
    cout << "Enter the book Id to update: ";
    cin >> updateId;
    cin.ignore();

    for (vector<Library>::iterator it = lib.begin(); it != lib.end(); ++it) {
        if (it->id == updateId) {
            cout << "Updating book details:\n";
            it->inputDetails();
            cout << "Book details updated.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void deleteBook(vector<Library>& lib){
    int deleteId;
    cout << "Enter the book Id to delete: ";
    cin >> deleteId;

    for (vector<Library>::iterator it = lib.begin(); it != lib.end(); ++it) {
        if (it->id == deleteId) {
            lib.erase(it);
            cout << "Book deleted.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

int main() {
    vector<Library> lib;
    int input = 0;
    string password;

    // Set the initial password
    while (!setPassword(password));

    while (true) {
        if (!checkPassword(password)) {
            cout << "Incorrect password! Access denied.\n";
            continue;
        }

        displayMenu();
        cin >> input;

        switch (input) {
        case 1:
            inputBookDetails(lib);
            break;
        case 2:
            displayBookDetails(lib);
            break;
        case 3:
            searchBook(lib);
            break;
        case 4:
            updateBook(lib);
            break;
        case 5:
            deleteBook(lib);
            break;
        case 6:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "!! You have entered a wrong value !!\n"
                 << "Please try again.....\n";
        }
    }

    return 0;
}
