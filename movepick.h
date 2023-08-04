#ifndef MOVEPICK_H_INCLUDED
#define MOVEPICK_H_INCLUDED

////
//// Includes
////

#include "depth.h"
#include "lock.h"
#include "position.h"


////
//// Types
////

/// MovePicker is a class which is used to pick one legal move at a time from
/// the current position.  It is initialized with a Position object and a few
/// moves we have reason to believe are good.  The most important method is
/// MovePicker::pick_next_move(), which returns a new legal move each time it
/// is called, until there are no legal moves left, when MOVE_NONE is returned.
/// In order to improve the efficiency of the alpha beta algorithm, MovePicker
/// attempts to return the moves which are most likely to be strongest first.

class MovePicker {

public:
  MovePicker(Position &p, bool pvnode, Move ttm, Move mk, Move k1, Move k2,
             Depth dpth);
  Move get_next_move();
  Move get_next_move(Lock &lock);
  int number_of_moves() const;
  int current_move_score() const;
  Bitboard discovered_check_candidates();

  static void init_phase_table();

private:
  void score_captures();
  void score_noncaptures();
  void score_evasions();
  void score_qcaptures();
  Move pick_move_from_list();
  
  Position *pos;
  Move ttMove, mateKiller, killer1, killer2;
  Bitboard pinned, dc;
  MoveStack moves[256], badCaptures[64];
  bool pvNode;
  Depth depth;
  int phaseIndex;
  int numOfMoves, numOfBadCaptures;
  int movesPicked, badCapturesPicked;
  bool finished;
};


////
//// Inline functions
////

/// MovePicker::discovered_check_candidates() returns a bitboard containing
/// all pieces which can possibly give discovered check.  This bitboard is
/// computed by the constructor function.

inline Bitboard MovePicker::discovered_check_candidates() {
  return dc;
}

#endif // !defined(MOVEPICK_H_INCLUDED)
