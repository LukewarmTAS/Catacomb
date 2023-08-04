#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

////
//// Includes
////

#include "depth.h"
#include "move.h"
#include "piece.h"


////
//// Types
////

/// The History class stores statistics about how often different moves have
/// been successful or unsuccessful during the current search.  These
/// statistics are used for reduction and move ordering decisions.

class History {

public:
  History();
  void clear();
  void success(Piece p, Move m, Depth d);
  void failure(Piece p, Move m);
  int move_ordering_score(Piece p, Move m) const;
  bool ok_to_prune(Piece p, Move m, Depth d) const;

private:
  int history[16][64];  // [piece][square]
  int successCount[16][64];
  int failureCount[16][64];
};


////
//// Constants and variables
////

/// HistoryMax controls how often the history counters will be scaled down:
/// When the history score for a move gets bigger than HistoryMax, all
/// entries in the table are divided by 2.  It is difficult to guess what
/// the ideal value of this constant is.  Scaling down the scores often has
/// the effect that parts of the search tree which have been searched
/// recently have a bigger importance for move ordering than the moves which
/// have been searched a long time ago.
///
/// Note that HistoryMax should probably be changed whenever the constant
/// OnePly in depth.h is changed.  This is somewhat annoying.  Perhaps it
/// would be better to scale down the history table at regular intervals?

const int HistoryMax = 50000;


#endif // !defined(HISTORY_H_INCLUDED)
