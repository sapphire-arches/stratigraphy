#ifndef _STRAT_NBT_NBTTAG_H_
#define _STRAT_NBT_NBTTAG_H_

#include <vector>
#include <stdio>

namespace stratigraphy{ namespace nbt {
    enum TagType {
        END         = 0,
        BYTE        = 1,
        SHORT       = 2,
        INT         = 3,
        LONG        = 4,
        FLOAT       = 5,
        DOUBLE      = 6,
        BYTE_ARRAY  = 7,
        STRING      = 8,
        LIST        = 9,
        COMPOUND    = 10,
        INT_ARRAY   = 11
    }
    
    class NBTTag {
        public:
            NBTTag();
            NBTTag(const NBTtag &tag);

            virtual ~NBTTag() = 0;

            virtual TagType GetTagType() = 0;
            virtual void WriteTo(std::ostream out) = 0;

            NBTTag & operator= (const NBTTag &);
        private:
            //No private data
    }

    class NBTTagCompound : public NBTTag {
        public:
            NBTTagCompound();
            NBTTagCompound(std::vector<NBTTag> tags);
            NBTTagCompound(const NBTTagCompound &tag);

            virtual ~NBTTagCompound();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream out);

            std::vector<NBTTag> GetTags();
            void AddTag(NBTTag t);
            
            NBTTag & operator= (const NBTTagCompound &rhs);
    }
}; };
#endif
