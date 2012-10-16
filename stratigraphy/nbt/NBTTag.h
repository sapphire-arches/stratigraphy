#ifndef _STRAT_NBT_NBTTAG_H_
#define _STRAT_NBT_NBTTAG_H_

#include <vector>
#include <map>
#include <ostream>
#include <istream>
#include <string>
#include <exception>
#include "Platform.h"

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
            virtual std::string& GetName() = 0;

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
            virtual std::string& GetName();

            NBTTagEnd& operator= (const NBTTagEnd& rhs);
        private:
    };

    class NBTTagByte : public NBTTag {
        public:
            NBTTagByte(std::istream& from);
            NBTTagByte(std::string& name);
            NBTTagByte(std::string& name, char value);

            virtual ~NBTTagByte();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::istream& in);
            virtual std::string& GetName();
            
            virtual char GetValue();
            virtual void SetValue(char c);

            NBTTagByte& operator= (const NBTTagByte& rhs);
        private:
            char _val;
            std::string _name;
    };

    class NBTTagShort : public NBTTag {
        public:
            NBTTagShort(std::istream& from);
            NBTTagShort(std::string& name);
            NBTTagShort(std::string& name, short val);
            
            virtual ~NBTTagShort();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& o);
            virtual void ReadFrom(std::istream& i);
            virtual std::string& GetName();
            
            virtual short GetValue();
            virtual void SetValue(short s);

            NBTTagShort& operator= (const NBTTagShort& rhs);
        private:
            short _val;
            std::string _name;
    };

    class NBTTagInt : public NBTTag {
        public:
            NBTTagInt(std::istream& from);
            NBTTagInt(std::string& name);
            NBTTagInt(std::string& name, int val);
            
            virtual ~NBTTagInt();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& o);
            virtual void ReadFrom(std::istream& i);
            virtual std::string& GetName();

            virtual int GetValue();
            virtual void SetValue(int i);

            NBTTagInt& operator= (const NBTTagInt& rhs);
        private:
            int _val;
            std::string _name;
    };  

    class NBTTagLong : public NBTTag {
        public:
            NBTTagLong(std::istream& from);
            NBTTagLong(std::string& name);
            NBTTagLong(std::string& name, int64 val);
            
            virtual ~NBTTagLong();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& o);
            virtual void ReadFrom(std::istream& i);
            virtual std::string& GetName();

            virtual int64 GetValue();
            virtual void SetValue(int64 i);

            NBTTagLong& operator= (const NBTTagLong& rhs);
        private:
            int64 _val;
            std::string _name;
    }; 

     class NBTTagFloat : public NBTTag {
        public:
            NBTTagFloat(std::istream& from);
            NBTTagFloat(std::string& name);
            NBTTagFloat(std::string& name, float val);
            
            virtual ~NBTTagLong();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& o);
            virtual void ReadFrom(std::istream& i);
            virtual std::string& GetName();

            virtual float GetValue();
            virtual void SetValue(float f);

            NBTTagFloat& operator= (const NBTTagFloat& rhs);
        private:
            float _val;
            std::string _name;
    };
  
    class NBTTagDouble : public NBTTag {
        public:
            NBTTagDouble(std::istream& from);
            NBTTagDouble(std::string& name);
            NBTTagDouble(std::string& name, double val);
            
            virtual ~NBTTagLong();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& o);
            virtual void ReadFrom(std::istream& i);
            virtual std::string& GetName();

            virtual double GetValue();
            virtual void SetValue(double d);

            NBTTagDouble& operator= (const NBTTagDouble& rhs);
        private:
            double _val;
            std::string _name;
    };

    class NBTTagCompound : public NBTTag {
        public:
            typedef std::map<std::string, NBTTag*> TagMap;

            NBTTagCompound(std::istream& f);
            NBTTagCompound(std::string& name);
            NBTTagCompound(std::string& name, std::vector<NBTTag*>& tags);
            NBTTagCompound(std::string& name, TagMap* tags);
            NBTTagCompound(const NBTTagCompound &tag);

            virtual ~NBTTagCompound();

            virtual TagType GetTagType();
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::istream& in);
            virtual std::string& GetName();

            TagMap GetTags();
            void AddTag(NBTTag& t);
            
            NBTTagCompound& operator= (const NBTTagCompound& rhs);
        private:
            void Init(std::string& name, TagMap* tags);

            TagMap _tags;
            std::string _name;
    };

    class NotImplementedException : public std::exception {
        public:
            NotImplementedException(const char* err) : _err(err) {
            }

            virtual const char* what() throw() {
                return _err;
            }
        private:
            const char *_err;
    };

    NBTTag& GetRead(TagType id, std::istream& from) {
        switch(id) {
            case END        : return *(new NBTTagEnd());
            case BYTE       : return *(new NBTTagByte(from));
            case SHORT      : return *(new NBTTagShort(from));
            case INT        : return *(new NBTTagInt(from));
            case LONG       : return *(new NBTTagLong(from));
            case FLOAT      : return *(new NBTTagFloat(from));
            case DOUBLE     : return *(new NBTTagDouble(from));
            /*
            case BYTE_ARRAY :
            case STRING     :
            case LIST       :
            */
            case COMPOUND   : return *(new NBTTagCompound(from));
            /*
            case INT_ARRAY  : 
            */
            default: throw NotImplementedException("We don't have a mapping for that tag type =(");
        };
    }
    
}; };
#endif
