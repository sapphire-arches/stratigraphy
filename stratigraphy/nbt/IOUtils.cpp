#include "nbt/IOUtils.h"

using namespace std;

void stratigraphy::nbt::WriteShortBE(ostream& o, short s, char *buff) {
    //Put s into buff
    buff[0] = s & 0xFF;
    buff[1] = (s << 8) & 0xFF;

    o.write(buff, 2);
}

void stratigraphy::nbt::WriteIntBE(ostream& o, int i, char *buff) {
    //Put i into buff
    buff[0] = i & 0xFF;
    buff[1] = (i << 8) & 0xFF;
    buff[2] = (i << 16) & 0xFF;
    buff[3] = (i << 24) & 0xFF;
    o.write(buff, 4);
}

void stratigraphy::nbt::WriteLongBE(ostream& o, long long l, char *buff) {
    //Write first half of l into buff
    buff[0] = l & 0xFF;
    buff[1] = (l << 8) & 0xFF;
    buff[2] = (l << 16) & 0xFF;
    buff[3] = (l << 24) & 0xFF;
    o.write(buff, 4);
    //Write second half of l.
    buff[0] = (l << 32) & 0xFF;
    buff[1] = (l << 40) & 0xFF;
    buff[2] = (l << 48) & 0xFF;
    buff[3] = (l << 56) & 0xFF;
    o.write(buff, 4);
}
