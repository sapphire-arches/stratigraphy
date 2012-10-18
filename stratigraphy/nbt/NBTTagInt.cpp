#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagInt::NBTTagInt(istream& from) {
    ReadFrom(from);
}

NBTTagInt::NBTTagInt(string& name) : _val(0), NBTTag(name) {
}

NBTTagInt::NBTTagInt(string& name, int val) : _val(0), NBTTag(name) {
}

NBTTagInt::~NBTTagInt() {
}

TagType NBTTagInt::GetTagType() {
    return INT;
}

void NBTTagInt::WriteData(ostream& o, char* buff) {
    WriteIntBE(o, _val, buff);
}

void NBTTagInt::ReadData(istream& is, char* buff) {
    _val = ReadIntBE(is, buff);
}

NBTTagInt& NBTTagInt::operator= (const NBTTagInt& rhs) {
    if (&rhs == this) {
        return *this;
    }
    
    delete &_name;

    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}

int NBTTagInt::GetValue() {
    return _val;
}

void NBTTagInt::SetValue(int i) {
    _val = i;
}
