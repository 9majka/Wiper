#include "Scanner.h"
#include "FileQueue.h"
#include "FileProcessor.h"
#include <vector>
#include <iostream>

int threadCount = 5;

int main(int argc, char *argv[])
{
    std::cout << "Hello, World!" << std::endl;

    FileQueue fileQueue;
    Scanner scanner(fileQueue);
    scanner.startScan("");

    std::vector<FileProcessor *> processors;

    for (int i = 0; i < threadCount; ++i)
    {
        FileProcessor * processor = new FileProcessor(fileQueue);
        processor->start();
        processors.push_back(processor);
    }

    int n;
    std::cout<<"Press any key to exit"<<std::endl;
    std::cin>>n;

    return 0;
}
