#ifndef _STRAT_NBT_NBTTREE_H_
#define _STRAT_NBT_NBTTREE_H_

#include <istream>
#include <ostream>
#include <string>

#include "nbt/NBTTag.h"

namespace stratigraphy { namespace nbt {
    class NBTTree {
        public:
            NBTTree(std::istream& from);
            NBTTree(std::string& name);
            NBTTree(const NBTTree &tree);

            virtual ~NBTTree();

            NBTTagCompound GetRoot();
            void WriteTo(std::ostream& o);
            
            NBTTree & operator= (const NBTTree &tree);

        private:
            NBTTagCompound _root;
    };
}; };

#endif
