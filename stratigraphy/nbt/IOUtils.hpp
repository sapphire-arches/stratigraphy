using namespace std;

namespace stratigraphy { namespace nbt {

inline void WriteShortBE(ostream& o, short s, char *buff) {
    //Put s into buff
    buff[1] = s & 0xFF;
    buff[0] = (s << 8) & 0xFF;

    o.write(buff, 2);
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in WriteShortBE()");
    }
}

inline void WriteIntBE(ostream& o, int i, char *buff) {
    //Put i into buff
    buff[3] = i & 0xFF;
    buff[2] = (i << 8) & 0xFF;
    buff[1] = (i << 16) & 0xFF;
    buff[0] = (i << 24) & 0xFF;
    o.write(buff, 4);
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in WriteIntBE()");
    }
}

inline void WriteLongBE(ostream& o, int64 l, char *buff) {
    //Write second half of l.
    buff[3] = (l << 32) & 0xFF;
    buff[2] = (l << 40) & 0xFF;
    buff[1] = (l << 48) & 0xFF;
    buff[0] = (l << 56) & 0xFF;
    o.write(buff, 4);
    //Write first half of l into buff
    buff[3] = l & 0xFF;
    buff[2] = (l << 8) & 0xFF;
    buff[1] = (l << 16) & 0xFF;
    buff[0] = (l << 24) & 0xFF;
    o.write(buff, 4);
    
    if (!o.good()) {
        throw ios_base::failure("Failed IO write in WriteLongBE()");
    }
}

inline void WriteFloatBE(ostream& o, float f, char *buff) {
    union {float ff; int i;};
    ff = f;
    WriteIntBE(o, i, buff);
}

inline void WriteDoubleBE(ostream& o, double d, char *buff) {
    union {double dd; int64 i;};
    dd = d;
    WriteIntBE(o, i, buff);
}

inline void WriteString(ostream& o, string& s, char *buff) {
    WriteShortBE(o, short(s.length()), buff); //write len
    o << s; //write string
}


/*****************************BEGIN READ FUNCTIONS******************************/


inline short ReadShortBE(istream& f, char *buff) {
    f.read(buff, 2);
    if (!f.good()) {
        throw ios_base::failure("Failed IO read in ReadShortBE()");
    }
    return ((buff[0] >> 8) & 0xFF) | ((buff[1]) & 0xFF);
}

inline int ReadIntBE(istream& f, char *buff) {
    f.read(buff, 4);
    if (!f.good()) {
        throw ios_base::failure("Failed IO read in ReadIntBE()");
    }
    return ((buff[0] >> 24) & 0x000000FF) |
           ((buff[1] >> 16) & 0x0000FF00) |
           ((buff[2] >> 8 ) & 0x00FF0000) |
           ((buff[3]      ) & 0xFF000000) ;
    
}

inline int64 ReadLongBE(istream& f, char *buff) {
    int i1 = ReadIntBE(f, buff);
    int i2 = ReadIntBE(f, buff);
    int64 temp = i1 | (((int64)i2) << 32);
    return temp;
}

inline float ReadFloatBE(istream& in, char *buff) {
    union {float f; int i;};
    i = ReadIntBE(in, buff);
    return f;
}

inline double ReadDoubleBE(istream& in, char *buff) {
    union {double d; int64 i;};
    i = ReadLongBE(in, buff);
    return i;
}

inline string ReadString(istream& i, char *buf) {
    short len = ReadShortBE(i, buf);
    if (len > 0) {
        char *buff = new char[len];
        i.read(buff, len);
        delete buff;
        return *(new string(buff, len));
    } else {
        return *(new string());
    }
}

}; };
