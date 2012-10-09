#ifndef _STRAT_NBT_IOUTILS_H_
#define _STRAT_NBT_IOUTILS_H_

#include <istream>
#include <ostream>
#include <climits>

#ifdef _MSC_VER
typedef __int64 int64;
#else
typedef long long int64;
#endif

namespace stratigraphy { namespace nbt {
    inline void WriteShortBE(std::ostream& o, short s, char *buff);
    inline void WriteIntBE  (std::ostream& o, int   i, char *buff);
    inline void WriteLongBE (std::ostream& o, int64 l, char *buff);
    
    inline short ReadShortBE(std::istream& from, char *buff);
    inline int   ReadIntBE  (std::istream& from, char *buff);
    inline int64 ReadLongBE (std::istream& from, char *buff);
}; };

#endif
