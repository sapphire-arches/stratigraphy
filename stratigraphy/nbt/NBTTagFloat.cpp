#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagFloat::NBTTagFloat(istream& in) {
    ReadFrom(in);
}

NBTTagFloat::NBTTagFloat(string& s) : _val(0), _name(s) {
}

NBTTagFloat::NBTTagFloat(string& s, float f) : _val(f), _name(s) {
}

TagType NBTTagFloat::GetTagType() {
    return FLOAT;
}

void NBTTagFloat::WriteTo(ostream& o) {
    o.put(char(FLOAT)); //write our header
    char buff[4];
    WriteString(o, _name, buff); //Write name
    WriteFloatBE(o, _val, buff); //Write our value.
}

void NBTTagFloat::ReadFrom(istream& is) {
    int i = is.get();
    if (i != FLOAT) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading Float tag, unexpected tag header byte %02x.";
        const string temp = (boost::format(fmt) % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    _name = ReadString(is, buff);
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

string& NBTTagFloat::GetName() {
    return _name;
}

float NBTTagFloat::GetValue() {
    return _val;
}

void NBTTagFloat::SetValue(float f) {
    _val = f;
}
