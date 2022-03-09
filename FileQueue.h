#ifndef UNTITLED_FILEQUEUE_H
#define UNTITLED_FILEQUEUE_H

#include <string>
#include <queue>

class FileQueue
{
public:
    void putFile(const std::string & filePath);
    std::string GetFile();

private:
    std::queue<std::string> mFileQueue;
};


#endif //UNTITLED_FILEQUEUE_H
