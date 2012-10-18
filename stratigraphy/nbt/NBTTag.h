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
            virtual void WriteTo(std::ostream& out);
            virtual void ReadFrom(std::istream& in);
            virtual std::string& GetName();
            virtual void SetName(std::string& name);

            NBTTag& operator= (const NBTTag &);
            std::ostream& operator<< (std::ostream& ost);
            std::istream& operator>> (std::istream& ins);
        protected:
            virtual void WriteData(std::ostream& o, char *buff) = 0;
            virtual void ReadData(std::istream& i, char *buff) = 0;
        private:
            std::string _name;
    };

    class NBTTagEnd : public NBTTag {
        public:
            NBTTagEnd();
            NBTTagEnd(const NBTTagEnd& tag);

            virtual ~NBTTagEnd();
            
            virtual TagType GetTagType();
            virtual std::string& GetName();
            virtual void SetName(std::string& name);

            NBTTagEnd& operator= (const NBTTagEnd& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
    };

    class NBTTagByte : public NBTTag {
        public:
            NBTTagByte(std::istream& from);
            NBTTagByte(std::string& name);
            NBTTagByte(std::string& name, char value);

            virtual ~NBTTagByte();

            virtual TagType GetTagType();
            virtual std::string& GetName();
            
            virtual char GetValue();
            virtual void SetValue(char c);

            NBTTagByte& operator= (const NBTTagByte& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            char _val;
    };

    class NBTTagShort : public NBTTag {
        public:
            NBTTagShort(std::istream& from);
            NBTTagShort(std::string& name);
            NBTTagShort(std::string& name, short val);
            
            virtual ~NBTTagShort();

            virtual TagType GetTagType();
            virtual std::string& GetName();
            
            virtual short GetValue();
            virtual void SetValue(short s);

            NBTTagShort& operator= (const NBTTagShort& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            short _val;
    };

    class NBTTagInt : public NBTTag {
        public:
            NBTTagInt(std::istream& from);
            NBTTagInt(std::string& name);
            NBTTagInt(std::string& name, int val);
            
            virtual ~NBTTagInt();

            virtual TagType GetTagType();

            virtual int GetValue();
            virtual void SetValue(int i);

            NBTTagInt& operator= (const NBTTagInt& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            int _val;
    };  

    class NBTTagLong : public NBTTag {
        public:
            NBTTagLong(std::istream& from);
            NBTTagLong(std::string& name);
            NBTTagLong(std::string& name, int64 val);
            
            virtual ~NBTTagLong();

            virtual TagType GetTagType();
            virtual std::string& GetName();

            virtual int64 GetValue();
            virtual void SetValue(int64 i);

            NBTTagLong& operator= (const NBTTagLong& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            int64 _val;
    }; 

     class NBTTagFloat : public NBTTag {
        public:
            NBTTagFloat(std::istream& from);
            NBTTagFloat(std::string& name);
            NBTTagFloat(std::string& name, float val);
            
            virtual ~NBTTagFloat();

            virtual TagType GetTagType();

            virtual float GetValue();
            virtual void SetValue(float f);

            NBTTagFloat& operator= (const NBTTagFloat& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            float _val;
    };
  
    class NBTTagDouble : public NBTTag {
        public:
            NBTTagDouble(std::istream& from);
            NBTTagDouble(std::string& name);
            NBTTagDouble(std::string& name, double val);
            
            virtual ~NBTTagDouble();

            virtual TagType GetTagType();

            virtual double GetValue();
            virtual void SetValue(double d);

            NBTTagDouble& operator= (const NBTTagDouble& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            double _val;
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

            TagMap GetTags();
            void AddTag(NBTTag& t);
            
            NBTTagCompound& operator= (const NBTTagCompound& rhs);
        protected:
            virtual void WriteData(std::ostream& o);
            virtual void ReadData(std::istream& i);
        private:
            void Init(std::string& name, TagMap* tags);

            TagMap _tags;
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
