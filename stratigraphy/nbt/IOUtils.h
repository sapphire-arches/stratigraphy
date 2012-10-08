#ifndef _STRAT_NBT_IOUTILS_H_
#define _STRAT_NBT_IOUTILS_H_

#include <istream>
#include <ostream>
#include <climits>

namespace stratigraphy { namespace nbt {
    void WriteShortBE(std::ostream& o, short s, char *buff);
    void WriteIntBE  (std::ostream& o, int   i, char *buff);
    void WriteLongBE (std::ostream& o, long  l, char *buff);
    
    short ReadShortBE(std::istream& from, char *buff);
    int   ReadIntBE  (std::istream& from, char *buff);
    long  ReadLongBE (std::istream& from, char *buff);
}; };

#endif
