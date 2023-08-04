////
//// Includes
////

#include <cstdlib>
#include <iostream>

#include "benchmark.h"
#include "bitboard.h"
#include "direction.h"
#include "endgame.h"
#include "evaluate.h"
#include "material.h"
#include "mersenne.h"
#include "misc.h"
#include "movepick.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "uci.h"
#include "ucioption.h"


//// 
//// Functions
////

int main(int argc, char *argv[]) {

  // Disable IO buffering
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  std::cout.rdbuf()->pubsetbuf(NULL, 0);
  std::cin.rdbuf()->pubsetbuf(NULL, 0);

  // Initialization

  init_mersenne();
  init_direction_table();
  init_bitboards();
  init_uci_options();
  Position::init_zobrist();
  Position::init_piece_square_tables();
  MaterialInfo::init();
  MovePicker::init_phase_table();
  init_eval(1);
  init_bitbases();
  init_threads();

  // Make random number generation less deterministic, for book moves
  int i = abs(get_system_time() % 10000);
  for(int j = 0; j < i; j++)
    genrand_int32();

  // Process command line arguments
  if(argc >= 2) {
    if(std::string(argv[1]) == "bench") {
      if(argc != 4) {
        std::cout << "Usage: catacomb bench <hash> <threads>" << std::endl;
        exit(0);
      }
      benchmark(std::string(argv[2]), std::string(argv[3]));
      return 0;
    }
  }

  // Print copyright notice
  std::cout << engine_name() << " by Luke Boncic" << std::endl;

  // Enter UCI mode
  uci_main_loop();

  return 0;
}
