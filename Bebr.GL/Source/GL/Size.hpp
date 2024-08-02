#pragma once
#include <cstdint>

namespace Bebr
{
namespace GL
{
#if		defined(WIN64)
typedef std::int64_t Size_t;
#elif	defined(WIN32)
typedef std::int32_t Size_t;
#endif
}
}
