#ifndef UCIOPTION_H_INCLUDED
#define UCIOPTION_H_INCLUDED

////
//// Includes
////

#include <string>


////
//// Variables
////

extern bool Chess960;


////
//// Prototypes
////

extern void init_uci_options();
extern void print_uci_options();
extern bool get_option_value_bool(const std::string &optionName);
extern int get_option_value_int(const std::string &optionName);
extern const std::string get_option_value_string(const std::string &optionName);
extern bool button_was_pressed(const std::string &buttonName);
extern void set_option_value(const std::string &optionName, 
                             const std::string &newValue);
extern void push_button(const std::string &buttonName);


#endif // !defined(UCIOPTION_H_INCLUDED)
