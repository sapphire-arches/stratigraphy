#ifndef _STRAT_NBT_IOUTILS_H_
#define _STRAT_NBT_IOUTILS_H_

#include <istream>
#include <ostream>

namespace stratigraphy { namespace nbt {
    void WriteShortBE(ostream o, short s);
    void WriteIntBE  (ostream o, int i);
    void WriteLongBE (ostream o, long i);
    
    short ReadShortBE(istream from);
    int   ReadIntBE  (istream from);
    long  ReadLongBE (istream from);
}; };

#endif
