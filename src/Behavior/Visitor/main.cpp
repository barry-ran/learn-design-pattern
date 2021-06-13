#include "Directory.h"
#include "File.h"
#include "ListVisitor.h"
#include "FileCountVisitor.h"
int main()
{
    // 以文件管理为例，数据结构为树，数据元素有两种类型：
    // 文件和目录
    // 创建了两种Visitor：
    // ListVisitor 列出所有文件和目录，以及大小
    // FileCountVisitor 统计所有文件个数
    
    Directory *root = new Directory("root");
    Directory *bin = new Directory("bin");
    Directory *tmp = new Directory("tmp");
    Directory *usr = new Directory("usr");

    root->addEntryy(bin);
    root->addEntryy(tmp);
    root->addEntryy(usr);
    bin->addEntryy(new File("vi", 3000));
    bin->addEntryy(new File("latex", 2000));    

    Directory *yuki = new Directory("yuki");
    Directory *hanako = new Directory("hanako");
    Directory *tomura = new Directory("tomura");

    usr->addEntryy(yuki);
    usr->addEntryy(hanako);
    usr->addEntryy(tomura);
    yuki->addEntryy(new File("diary.html", 100));
    hanako->addEntryy(new File("memo.tex", 1024));
    tomura->addEntryy(new File("junk.mail", 40));

    auto list = new ListVisitor;
    root->accept(list);

    auto fileCount = new FileCountVisitor;
    root->accept(fileCount);
    
    
    delete root;    
    delete list;
    delete fileCount;
    return 0;
}