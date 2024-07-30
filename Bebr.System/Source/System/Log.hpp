#pragma once

#ifdef DEBUG
#include <iostream>
#define LOG(message) std::cout << message
#else
#define LOG(message)
#endif
#define LOGLN(message) LOG(message); LOG('\n');
