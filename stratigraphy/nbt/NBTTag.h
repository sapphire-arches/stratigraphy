#ifndef _STRAT_NBT_NBTTAG_H_
#define _STRAT_NBT_NBTTAG_H_

#include <vector>
#include <ostream>
#include <istream>
#include <string>

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
    };
    
    class NBTTag {
        public:
            NBTTag();
            NBTTag(const NBTTag &tag);

            virtual ~NBTTag() = 0;

            virtual TagType GetTagType() = 0;
            virtual void WriteTo(std::ostream& out) = 0;
            virtual void ReadFrom(std::istream& in) = 0;

            NBTTag& operator= (const NBTTag &);
            std::ostream& operator<< (std::ostream& ost);
            std::istream& operator>> (std::istream& ins); 
        private:
            //No private data
    };

    class NBTTagEnd : public NBTTag {
        public:
            NBTTagEnd();
            NBTTagEnd(const NBTTagEnd& tag);

            virtual ~NBTTagEnd();
            
            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::istream& in);

            NBTTagEnd& operator= (const NBTTagEnd& rhs);
        private:
            //No data
    };

    class NBTTagByte : public NBTTag {
        public:
            NBTTagByte(std::string* name);
            NBTTagByte(std::string* name, char value);

            virtual ~NBTTagByte();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::ostream& in);

            NBTTagByte& operator= (const NBTTagEnd& rhs);
        private:
            char _val;
            std::string* _name;
    };

    class NBTTagCompound : public NBTTag {
        public:
            NBTTagCompound(std::string* name);
            NBTTagCompound(std::string* name, std::vector<NBTTag*>* tags);
            NBTTagCompound(const NBTTagCompound &tag);

            virtual ~NBTTagCompound();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::istream& in);

            std::vector<NBTTag&> GetTags();
            void AddTag(NBTTag& t);
            
            NBTTagCompound& operator= (const NBTTagCompound& rhs);
        private:
            void Init(std::string* name, std::vector<NBTTag*>* tags);

            std::vector<NBTTag*> _tags;

            std::string _name;
    };
}; };
#endif
