#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"
#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagByte::NBTTagByte(string& name) : _name(name), _val(0) {
}

NBTTagByte::NBTTagByte(string& name, char val) : _name(name), _val(val) {
}

NBTTagByte::~NBTTagByte() {
}

TagType NBTTagByte::GetTagType() {
    return BYTE;
}

void NBTTagByte::WriteData(ostream& out) {
    char buff[4];
    WriteString(out, _name, buff); //Write name
    out.put(_val); //Write our value.
}

void NBTTagByte::ReadData(istream& is) {
    char buff[4];
    _name = ReadString(is, buff);
    _val = is.get();
}

NBTTagByte& NBTTagByte::operator= (const NBTTagByte& rhs) {
    if (this == &rhs)
        return *this;
    
    delete &_name;
    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}

string& NBTTagByte::GetName() {
    return _name;
}

char NBTTagByte::GetValue() {
   return _val;
}

void NBTTagByte::SetValue(char c) {
    _val = c;
}
