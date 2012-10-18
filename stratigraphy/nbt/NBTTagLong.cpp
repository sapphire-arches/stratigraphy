#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagLong::NBTTagLong(istream& from) {
    ReadFrom(from);
}

NBTTagLong::NBTTagLong(string& name) : _val(0), NBTTag(name) {
}

NBTTagLong::NBTTagLong(string& name, int64 val) : _val(val), NBTTag(name) {
}

NBTTagLong::~NBTTagLong() {
}

TagType NBTTagLong::GetTagType() {
    return LONG;
}

void NBTTagLong::WriteData(ostream& o, char *buff) {
    WriteLongBE(o, _val, buff);
}

void NBTTagLong::ReadData(istream& is, char *buff) {
    _val = ReadLongBE(is, buff);
}

NBTTagLong& NBTTagLong::operator= (const NBTTagLong& rhs) {
    if (&rhs == this) {
        return *this;
    }

    delete &_name;
    
    _name = string(rhs._name);
    _val = rhs._val;
}

int64 NBTTagLong::GetValue() {
    return _val;
}

void NBTTagLong::SetValue(int64 i) {
    _val = i;
}
