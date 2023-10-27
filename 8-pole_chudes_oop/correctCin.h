#ifndef CORRECTCIN_H
#define CORRECTCIN_H

std::string getNline(std::string u, int N);

class correctCin
{
private:
    std::string m_url;
public:
    correctCin();

    std::string corMenu();

    std::string corEnd();

    std::string corLet();

    ~correctCin() {};
};

#endif
