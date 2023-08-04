#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED


////
//// Includes
////

#include <string>

#include "move.h"
#include "position.h"


////
//// Types
////

struct BookEntry {
  uint64_t key;
  uint16_t move;
  uint16_t count;
  uint16_t n;
  uint16_t sum;
};

class Book {

public:
  // Constructors
  Book();

  // Open and close book files
  void open(const std::string &fName);
  void close();

  // Testing if a book is opened
  bool is_open() const;

  // The file name of the currently active book
  const std::string file_name() const;

  // Get a book move for a given position
  Move get_move(const Position &pos) const;

private:
  int find_key(uint64_t key) const;
  void read_entry(BookEntry &entry, int n) const;

  std::string fileName;
  FILE *bookFile;
  int bookSize;
};


////
//// Global variables
////

extern Book OpeningBook;


#endif // !defined(BOOK_H_INCLUDED)
