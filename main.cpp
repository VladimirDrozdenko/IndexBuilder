#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

const size_t LIBSIZE = 100;

struct Book {
  string title;
  string author;
  string isbn;
};

static unsigned int randNumber() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100);

  return dist6(rng);
}

void buildLib(vector<Book>& books) {
  for (int i = 0; i < LIBSIZE; ++i) {

    char buffer[5];
    snprintf(buffer, sizeof(buffer), "%u", randNumber());

    string randStr(buffer);
    Book book;
    book.author = "author" + randStr;
    book.isbn = "isbn" + randStr;
    book.title = "title" + randStr;

    books.push_back(book);
  }
}

void buildTitleIndex(const vector<Book>& library, vector<size_t>& index) {
  sort(index.begin(), index.end(), [&library](int a, int b) { return library[a].title < library[b].title; });
}

void buildAuthorIndex(const vector<Book>& library, vector<size_t>& index) {
  sort(index.begin(), index.end(), [&library](int a, int b) { return library[a].author < library[b].author; });
}

void buildISBNIndex(const vector<Book>& library, vector<size_t>& index) {
  sort(index.begin(), index.end(), [&library](int a, int b) { return library[a].isbn < library[b].isbn; });
}

int main() {
  vector<Book> library;
  buildLib(library);

  vector<size_t> index_title, index_author, index_isbn;
  for (size_t i = 0; i < LIBSIZE; ++i) {
    index_title.push_back(i);
    index_author.push_back(i);
    index_isbn.push_back(i);
  }
  buildTitleIndex(library, index_title);
  buildAuthorIndex(library, index_author);
  buildISBNIndex(library, index_isbn);

  for (size_t i = 0; i < LIBSIZE; ++i) {
    cout << library[index_title[i]].title << endl;
  }

  for (size_t i = 0; i < LIBSIZE; ++i) {
    cout << library[index_author[i]].author << endl;
  }

  for (size_t i = 0; i < LIBSIZE; ++i) {
    cout << library[index_isbn[i]].isbn << endl;
  }

  return 0;
}
