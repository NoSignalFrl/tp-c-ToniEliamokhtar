#include "book.h"
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// ----- Constructeurs -----
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}


// ----- Getters -----
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }


// ----- Setters -----
void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }
void Book::setISBN(const string& i) { isbn = i; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerName(const string& name) { borrowerName = name; }


// ----- Méthodes principales -----

// Emprunter un livre
void Book::checkOut(const string& borrower) {
    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
        cout << "📚 Livre emprunté avec succès par " << borrower << " !" << endl;
    } else {
        cout << "❌ Le livre \"" << title << "\" est déjà emprunté par " << borrowerName << "." << endl;
    }
}

// Retourner un livre
void Book::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        borrowerName.clear();
        cout << "✅ Livre retourné avec succès !" << endl;
    } else {
        cout << "ℹ️ Le livre \"" << title << "\" est déjà disponible." << endl;
    }
}

// Affichage console
string Book::toString() const {
    string status = isAvailable ? "Disponible" : "Emprunté par " + borrowerName;
    return "Titre: " + title + " | Auteur: " + author + " | ISBN: " + isbn + " | " + status;
}

// Format pour sauvegarde (fichier)
string Book::toFileFormat() const {
    // Format : title|author|isbn|isAvailable|borrowerName
    ostringstream out;
    out << title << "|" << author << "|" << isbn << "|" 
        << (isAvailable ? "1" : "0") << "|" << borrowerName;
    return out.str();
}

// Lecture à partir du fichier
void Book::fromFileFormat(const string& line) {
    vector<string> parts;
    string token;
    stringstream ss(line);

    while (getline(ss, token, '|')) {
        parts.push_back(token);
    }

    if (parts.size() >= 5) {
        title = parts[0];
        author = parts[1];
        isbn = parts[2];
        isAvailable = (parts[3] == "1" || parts[3] == "true");
        borrowerName = parts[4];
    }
}
