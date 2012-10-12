#include "nbt/NBTTag.h"

#include <string>
#include <boost/format.hpp>

#include "nbt/IOUtils.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagCompound::NBTTagCompound(string& name) {
    Init(name, new TagMap());
}

NBTTagCompound::NBTTagCompound(string& name, vector<NBTTag*>& tagList) {
    TagMap* tags = new TagMap();

    typename vector<NBTTag*>::iterator it;
    for(it = tagList.begin(); it != tagList.end(); it++) {
        string name = (*it)->GetName();
        tags->insert(make_pair(name, (*it)));
    }

    Init(name, tags);
}

void NBTTagCompound::Init(string& name, TagMap* tags) {
    _name = name;
    _tags = *tags;
}

NBTTagCompound::~NBTTagCompound() {
    delete &_tags;
    delete &_name;
}

TagType NBTTagCompound::GetTagType() {
    return COMPOUND;
}

string& NBTTagCompound::GetName() {
    return _name;
}

void NBTTagCompound::WriteTo(ostream& out) {
    //General buffer
    char buff[4];
    out.put(GetTagType()); //Write tag header
    //Write name, if there is one.
    WriteString(out, _name, buff);

    typename TagMap::iterator it;
    for (it = _tags.begin(); it != _tags.end(); it++) {
        it->second->WriteTo(out);
    }
    out.put(0); //Ending TAG_END
}

void NBTTagCompound::ReadFrom(istream& in) {
    char buff[4];

    int i = in.get();

    if (i != COMPOUND) {
        in.setstate(ios_base::failbit);
        const string fmt = "Error reading Compound tag, unexpected tag header byte %02x.";
        const string temp = (boost::format(fmt) % i).str();
        throw ios_base::failure(temp);
    }

    delete &_tags;
    _tags = *(new TagMap());
    
    while ((i = in.peek()) != 0) {
        NBTTag& tag = GetRead(TagType(i), in);
        _tags[tag.GetName()] = &tag;
    }
}
