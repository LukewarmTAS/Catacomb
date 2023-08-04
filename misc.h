#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED


////
//// Includes
////

#include <string>


////
//// Constants
////


/// Version number.  If this is left empty, the current date (in the format
/// YYMMDD) is used as a version number.

const std::string EngineVersion = "1";


////
//// Macros
////

#define Min(x, y) (((x) < (y))? (x) : (y))
#define Max(x, y) (((x) < (y))? (y) : (x))


////
//// Prototypes
////

extern const std::string engine_name();
extern int get_system_time();
extern int cpu_count();
extern int Bioskey();


#endif // !defined(MISC_H_INCLUDED)
