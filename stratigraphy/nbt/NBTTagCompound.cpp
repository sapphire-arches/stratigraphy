#include "nbt/NBTTag.h"
#include string

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagCompound::NBTTagCompound(string name) : _tags(), _name(name) {
}

NBTTagCompound::NBTTagCompound(string name, vector<NBTTag> tags) : _name(name) {
    this->_tags = tags;
}

NBTTagCompound::~NBTTagCompound() {
    //Nothing to do here
}

TagType NBTTagCompound::GetTagType() {
    return TagType.COMPOUND;
}

void NBTTagCompound::WriteTo(ostream out) {
    out.put(int(TagType.COMPOUND)); //Write tag header
    //Write name, if there is one.

}
