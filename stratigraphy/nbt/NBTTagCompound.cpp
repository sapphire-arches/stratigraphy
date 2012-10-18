#include "nbt/NBTTag.h"

#include <string>
#include <boost/format.hpp>

#include "nbt/IOUtils.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagCompound::NBTTagCompound(string& name) : NBTTag(name) {
    _tags = *(new TagMap());
}

NBTTagCompound::NBTTagCompound(string& name, vector<NBTTag*>& tagList) : NBTTag(name) {
    TagMap* tags = new TagMap();

    typename vector<NBTTag*>::iterator it;
    for(it = tagList.begin(); it != tagList.end(); it++) {
        string name = (*it)->GetName();
        tags->insert(make_pair(name, (*it)));
    }

    _tags = *tags;
}

NBTTagCompound::~NBTTagCompound() {
    delete &_tags;
}

TagType NBTTagCompound::GetTagType() {
    return COMPOUND;
}

void NBTTagCompound::WriteData(ostream& out, char* buff) {
    typename TagMap::iterator it;
    for (it = _tags.begin(); it != _tags.end(); it++) {
        it->second->WriteTo(out);
    }
    out.put(0); //Ending TAG_END
}

void NBTTagCompound::ReadData(istream& in, char* buff) {
    delete &_tags;
    _tags = *(new TagMap());

    int i;

    while ((i = in.peek()) != 0) {
        NBTTag& tag = GetRead(TagType(i), in);
        _tags[tag.GetName()] = &tag;
    }
}
