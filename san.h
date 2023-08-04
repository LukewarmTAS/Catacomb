#ifndef SAN_H_INCLUDED
#define SAN_H_INCLUDED

////
//// Includes
////

#include <string>

#include "move.h"
#include "position.h"
#include "value.h"


////
//// Prototypes
////

extern const std::string move_to_san(Position &pos, Move m);
extern Move move_from_san(Position &pos, const std::string &str);
extern const std::string line_to_san(const Position &pos, Move line[],
                                     int startColumn, bool breakLines);
extern const std::string pretty_pv(const Position &pos, int time, int depth,
                                   uint64_t nodes, Value score, Move pv[]);


#endif // !defined(SAN_H_INCLUDED)
