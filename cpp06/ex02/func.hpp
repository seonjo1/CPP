#ifndef FUNC_HPP
# define FUNC_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>
# include <new>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif