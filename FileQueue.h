#ifndef UNTITLED_FILEQUEUE_H
#define UNTITLED_FILEQUEUE_H

#include "Utils.h"
#include <string>
#include <queue>

class FileQueue
{
public:
    void putFile(const M_STRING & filePath);
    M_STRING GetFile();

private:
    std::queue<M_STRING> mFileQueue;
};


#endif //UNTITLED_FILEQUEUE_H
