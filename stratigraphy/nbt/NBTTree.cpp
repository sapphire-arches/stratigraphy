#include "nbt/NBTTree.h"

using namespace stratigraphy::nbt;

NBTTree::NBTTree() : root() {
}

NBTTree::NBTTree(const NBTTree &other) : root (other.root) {
}

NBTTree::~NBTTree() {
}

NBTTree::GetRoot() {
    return root;
}

NBTTree &NBTTree::operator= (const NBTTree &other) {
    if (&other == this) {
        return *this;
    }
    root = other.root;
    return *this;
}
