#include<iostream>
#include<string>
bool password_check(const std::string& password) // 只能包含字母，数字，长度限制 6~15 之间
{
    if (password.size() < 6 || password.size() > 15) return false;
    for (auto& e : password)
    {
        if ((e >= '0' && e <= '9') || (e > 'A' && e < 'Z') || (e > 'a' && e < 'z'))
            continue;
        else return false;
    }
    return true;
}

int main()
{
    bool ret = password_check("THXthx0210");
    std::cout << ret << std::endl;
    return 0;
}