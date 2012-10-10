#include "nbt/NBTTag.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagEnd::NBTTagEnd() {
}

NBTTagEnd::NBTTagEnd(const NBTTagEnd& tag) {
}

NBTTagEnd::~NBTTagEnd() {
}

TagType NBTTagEnd::GetTagType() {
    return END;
}

void NBTTagEnd::WriteTo(std::ostream& out) {
    out.put(0);
}

void NBTTagEnd::ReadFrom(std::istream& in) {
    if (in.get() != 0) {
        in.setstate(ios_base::iostate::failbit);
    }
}

NBTTagEnd& NBTTagEnd::operator= (const NBTTagEnd &rhs) {
    return *this;
}
