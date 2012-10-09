Beware IOUtils!
===============
It relies on stupid endianness tricks, that I really should get rid of, but
don't know a proper way to implement them. I cannot garuntee that it will work
on any compiler/ system other that 64 bit Arch Linux with GCC 4.7.1. I have
tried to use conditional compilation to help with any OS incompatabilities,
but I cannot test any Windows-specific patches for the sole reason that I
do not have access to an MSVC compiler.
