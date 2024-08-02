#pragma once
#include <cstdint>

namespace Bebr
{
namespace GL
{
#ifdef WIN64
typedef std::int64_t Size_t;
#else
typedef std::int32_t Size_t;
#endif
}
}
