#include "../letterfunc/src/utf8func.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
    {
    if(argc != 3)
        {
        printf("all2lower <input> <output>\n");
        return 0;
        }
    FILE* in = fopen(argv[1],"rb");
    if(in)
        {
        FILE* out = fopen(argv[2], "wb");
        if(out)
            {
            fseek(in, 0, SEEK_END);
            size_t size = ftell(in);
            printf("size %ld\n", size);
            rewind(in);
            char* buffer = new char[size + 1];
            fread(buffer, sizeof(char), size, in);
            buffer[size] = 0;
            const char * newbuffer = allToLowerUTF8(buffer);
            fwrite(newbuffer, sizeof(char), strlen(newbuffer), out);
            fclose(out);
            }
        else
            {
            printf("cannot open %s for writing\n", argv[2]);
            fclose(in);
            return -1;
            }
        fclose(in);
        }
    else
        {
        printf("cannot open %s for reading\n", argv[1]);
        return -1;
        }
    return 0;
    }
