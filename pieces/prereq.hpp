#include<ostream>

#if defined(__unix__)
#include "../piece.hpp"
#include "../tile.hpp"
#elif defined(_WIN64)
#include "..\piece.hpp"
#include "..\tile.hpp"
#elif defined(__APPLE__)
#include "../piece.hpp"
#include "../tile.hpp"
#endif