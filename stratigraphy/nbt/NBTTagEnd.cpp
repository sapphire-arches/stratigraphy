#include "nbt/NBTTag.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagEnd::NBTTagEnd() : _named(false) {
}

NBTTagEnd::NBTTagEnd(string* name) : _named(true) {
}

NBTTagEnd::NBTTagEnd(const NBTTagEnd& tag) : _named(tag._named) {
}

NBTTagEnd::~NBTTagEnd() {
}

void NBTTagEnd::WriteTo(std::ostream& out) {
    if (_named) {
        out.put(0);
    }
}

void NBTTagEnd::ReadFrom(std::istream& in) {
    //TODO: Make sure that this will actually work
    _named = false;
    if (in.peek() == 0) {
        in.get();
        _named = true;
    }
}

NBTTagEnd& NBTTagEnd::operator= (const NBTTagEnd &rhs) {
    _named = rhs._named;
    return *this;
}
