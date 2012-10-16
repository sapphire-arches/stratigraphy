#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagLong::NBTTagLong(istream& from) {
    ReadFrom(from);
}

NBTTagLong::NBTTagLong(string& name) : _val(0), _name(name) {
}

NBTTagLong::NBTTagLong(string& name, int64 val) : _val(val), _name(name) {
}

NBTTagLong::~NBTTagLong() {
}

TagType NBTTagLong::GetTagType() {
    return LONG;
}

void NBTTagLong::WriteTo(ostream& o) {
    o.put(char(LONG));
    char buff[4];
    WriteString(o, _name, buff);
    WriteLongBE(o, _val, buff);
}

void NBTTagLong::ReadFrom(istream& is) {
    int i = is.get();
    if (i != LONG) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading long tag, unexpected tag header byte %02x.";
        const string temp = (boost::format(fmt) % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    _name = ReadString(is, buff);
    _val = ReadLongBE(is, buff);

}

string& NBTTagLong::GetName() {
    return _name;
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
