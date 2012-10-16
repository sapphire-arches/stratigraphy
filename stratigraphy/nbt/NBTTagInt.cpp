#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagInt::NBTTagInt(istream& from) {
    ReadFrom(from);
}

NBTTagInt::NBTTagInt(string& name) : _val(0), _name(name) {
}

NBTTagInt::NBTTagInt(string& name, int val) : _val(0), _name(name) {
}

NBTTagInt::~NBTTagInt() {
}

TagType NBTTagInt::GetTagType() {
    return INT;
}

void NBTTagInt::WriteTo(ostream& o) {
    o.put(char(INT));
    char buff[4];
    WriteString(o, _name, buff);
    WriteIntBE(o, _val, buff);
}

void NBTTagInt::ReadFrom(istream& is) {
    int i = is.get();
    if (i != INT) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading int tag, unexpected tag header byte %02x.";
        const string temp = (boost::format(fmt) % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    _name = ReadString(is, buff);
    _val = ReadIntBE(is, buff);
}

string& NBTTagInt::GetName() {
    return _name;
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

void NBTTAgInt::SetValue(int i) {
    _val = i;
}
