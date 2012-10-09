#include "nbt/IOUtils.h"

using namespace std;

inline void stratigraphy::nbt::WriteShortBE(ostream& o, short s, char *buff) {
    //Put s into buff
    buff[1] = s & 0xFF;
    buff[0] = (s << 8) & 0xFF;

    o.write(buff, 2);
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in stratigraphy::nbt::WriteShortBE()");
    }
}

inline void stratigraphy::nbt::WriteIntBE(ostream& o, int i, char *buff) {
    //Put i into buff
    buff[3] = i & 0xFF;
    buff[2] = (i << 8) & 0xFF;
    buff[1] = (i << 16) & 0xFF;
    buff[0] = (i << 24) & 0xFF;
    o.write(buff, 4);
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in stratigraphy::nbt::WriteIntBE()");
    }
}

inline void stratigraphy::nbt::WriteLongBE(ostream& o, int64 l, char *buff) {
    //Write second half of l.
    buff[3] = (l << 32) & 0xFF;
    buff[2] = (l << 40) & 0xFF;
    buff[1] = (l << 48) & 0xFF;
    buff[0] = (l << 56) & 0xFF;
    o.write(buff, 4);
    //Write first half of l into buff
    buff[3] = l & 0xFF;
    buff[2] = (l << 8) & 0xFF;
    buff[1] = (l << 16) & 0xFF;
    buff[0] = (l << 24) & 0xFF;
    o.write(buff, 4);
    
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in stratigraphy::nbt::WriteLongBE()");
    }
}

inline short stratigraphy::nbt::ReadShortBE(istream& f, char *buff) {
    f.read(buff, 2);
    if (!f.good()) {
        throw ios_base::failure("Failed IO read in stratigraphy::nbt::ReadShortBE()");
    }
    return ((buff[0] >> 8) & 0xFF) | ((buff[1]) & 0xFF);
}

inline int stratigraphy::nbt::ReadIntBE(istream& f, char *buff) {
    f.read(buff, 4);
    if (!f.good()) {
        throw ios_base::failure("Failed IO read in stratigraphy::nbt::ReadIntBE()");
    }
    return ((buff[0] >> 24) & 0x000000FF) |
           ((buff[1] >> 16) & 0x0000FF00) |
           ((buff[2] >> 8 ) & 0x00FF0000) |
           ((buff[3]      ) & 0xFF000000) ;
    
}

inline int64 stratigraphy::nbt::ReadLongBE(istream& f, char *buff) {
    int i1 = ReadIntBE(f, buff);
    int i2 = ReadIntBE(f, buff);
    int64 temp = i1 | (((int64)i2) << 32);
    return temp;
}
