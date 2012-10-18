#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

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
    char buff[4];
    WriteString(out, _name, buff);
    WriteData(out, buff);
}

void NBTTag::ReadFrom(istream& is) {
    int i = is.get();
    if (i != GetTagType()) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading tag, expected tag header byte %02x, got %02x.";
        const string temp = (boost::format(fmt) % GetTagType() % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    _name = ReadString(is, buff);
    ReadData(is, buff);
}
