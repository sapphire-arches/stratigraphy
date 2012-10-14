#ifndef _STRATIGRAPHY_PLATFORM_H_
#define _STRATIGRAPHY_PLATFORM_H_

namespace stratigraphy {
#ifdef _MSC_VER
typedef __int64 int64;
#else
typedef long long int64;
#endif
}

#endif
