#include "Common.hpp"

#include <cmath>
#include <fstream>
#include <streambuf>

using namespace std;

double common::pi()
{
    return std::acos(-1.0);
}

// ����һ��float�Ħ�
float common::pif()
{
    return std::acos(-1.0f);
}

// ��ȡ�ļ��е�ASCII�ı����ݣ�������һ���Զ�ȡ�������ļ����ݣ�string����
std::string common::loadASCIITextFile(const std::string &filepath)
{
    ifstream file(filepath);
    string output;

    // Ԥ����ռ��Ż����ֽ�ָ���Ƶ��ļ�β����Ȼ������ڴ����ƶ�ָ������ͷ
    file.seekg(0, ios::end);
    output.reserve(file.tellg());
    file.seekg(0, ios::beg);

    // ������������֮��������ַ������Ƶ�output�ַ�����
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
