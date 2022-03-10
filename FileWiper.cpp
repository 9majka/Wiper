#include "FileWiper.h"
#include <iostream>

bool FileWiper::wipeFile(const M_STRING & filePath)
{
    std::cout<<"File wiping: " << filePath.c_str() << std::endl;
    return true;
}
