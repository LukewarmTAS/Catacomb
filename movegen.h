#ifndef MOVEGEN_H_INCLUDED
#define MOVEGEN_H_INCLUDED

////
//// Includes
////

#include "position.h"


////
//// Prototypes
////

extern int generate_captures(const Position &pos, MoveStack *mlist);
extern int generate_noncaptures(const Position &pos, MoveStack *mlist);
extern int generate_checks(const Position &pos, MoveStack *mlist, Bitboard dc);
extern int generate_evasions(const Position &pos, MoveStack *mlist);
extern int generate_legal_moves(const Position &pos, MoveStack *mlist);
extern Move generate_move_if_legal(const Position &pos, Move m,
                                   Bitboard pinned);

#endif // !defined(MOVEGEN_H_INCLUDED)
