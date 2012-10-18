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

void NBTTag::WriteTo(ostream& out) {
    out.put(GetTagType());
    WriteData(out);
}

void NBTTag::ReadFrom(istream& i) {
    int i = is.get();
    if (i != GetTagType()) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading tag, expected tag header byte %02x, got %02x.";
        const string temp = (boost::format(fmt) % GetTagType() % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    SetName(
    ReadData(i);
}
