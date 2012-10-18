#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagFloat::NBTTagFloat(istream& in) {
    ReadFrom(in);
}

NBTTagFloat::NBTTagFloat(string& s) : _val(0), NBTTag(s) {
}

NBTTagFloat::NBTTagFloat(string& s, float f) : _val(f), NBTTag(s) {
}

TagType NBTTagFloat::GetTagType() {
    return FLOAT;
}

void NBTTagFloat::WriteData(ostream& o, char* buff) {
    WriteFloatBE(o, _val, buff); //Write our value.
}

void NBTTagFloat::ReadData(istream& is, char* buff) {
    _val = ReadFloatBE(is, buff);
}

NBTTagFloat& NBTTagFloat::operator= (const NBTTagFloat& rhs) {
    if (&rhs == this) {
        return *this;
    }

    delete &_name;

    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}

float NBTTagFloat::GetValue() {
    return _val;
}

void NBTTagFloat::SetValue(float f) {
    _val = f;
}
