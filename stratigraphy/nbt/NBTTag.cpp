#include "nbt/NBTTag.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTag::NBTTag() {
    //Do nothing
}

NBTTag::NBTTag(const NBTTag &tag) {
    //Do nothing
}

NBTTag & NBTTag::operator=(const NBTTag &rhs) {
    return *this;
}

ostream& NBTTag::operator<<(ostream& ost) {
    WriteTo(ost);
    return ost;
}

istream& NBTTag::operator>>(istream& ins) {
    ReadFrom(ins);
    return ins;
}
