#include "Common.hpp"

#include <cmath>
#include <fstream>
#include <streambuf>

using namespace std;

double common::pi()
{
    return std::acos(-1.0);
}

// 返回一个float的π
float common::pif()
{
    return std::acos(-1.0f);
}

// 读取文件中的ASCII文本内容，并返回一次性读取的整个文件内容，string类型
std::string common::loadASCIITextFile(const std::string &filepath)
{
    ifstream file(filepath);
    string output;

    // 预分配空间优化，现将指针移到文件尾部，然后分配内存再移动指针至开头
    file.seekg(0, ios::end);
    output.reserve(file.tellg());
    file.seekg(0, ios::beg);

    // 将两个迭代器之间的所有字符都复制到output字符串中
    output.assign(
        istreambuf_iterator<char>(file),
        istreambuf_iterator<char>()
    );

    return output;
}

const char *common::transformStringToCStr(const std::string &str)
{
    return str.c_str();
}
