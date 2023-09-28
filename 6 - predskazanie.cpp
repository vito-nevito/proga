#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
#include <ctime>

int main()
{
    srand(time(NULL));
    SetConsoleCP (CP_UTF8) ;
    SetConsoleOutputCP (CP_UTF8) ;
    std::string music[] {"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1","Червяк Даргомыжский","Russian Ebunny","Enemy Imagine dragons"," Зизазай Огги и тараканы","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","Так закалялась сталь Гражданская оборона","За деньги да Инстасамка","Bad habits Ed sheeran"};
    std::string movies[] {"Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести","Джентльмены","Ван Хельсинк","Операция Ы","Драйв","Большая игра","Игра в имитацию","Всё везде и сразу","Форрест Гамп","Терминал","Не смотрите наверх"};
    std::string actors[] {"Райан Гослинг", "Кристиан Бейл", "Джеки Чан","Эндрю Гарфилд","Леонардо ДиКаприо","Бенедикт Кембербетч","Мэтью Макконахи","Дэвид Линч","Дэниэлл Рэдклифф","Джейк Джиллехолл","Александр Петров","Рональд Рейган","Том Круз","Брэд Питт"};
    std::string actriss[] {"Наталия Крачковская", "Меган Фокс", "Джениффер Лопез","Эмма Стоун","Эмма Уотсон","Кира Найтли","Милла Йовович","Марго Робби","Мерил Стрип","Скарлет Йоханссон","Александра Бортич","Анджелина Джоли","Шарлиз Терон","Ингеборга Дапкунайте"};
    std::string celeb[] {"Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева","Павел Воля","Криштиану Роналду","Борис Бурда","Ким Кардашьян","Клава Кока"};
    std::string data;
    std::cout << "Введите дату рождения: ";
    std::cin >> data;
    int sum = 0;
    int m = 0;
    int coun = 0;
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] != '.')
            sum += int(data[i]) - 48;
        else
            coun++;
        if(data[i] != '.' && coun == 1)
        {
            m += int(data[i]) - 48;
            i++;
            if(data[i] != '.')
            {
                m = m * 10 + int(data[i]) - 48;
                sum += int(data[i]) - 48;
            }
        }
    }
    // std::cout << sum << std::endl;
    // std::cout << m << std::endl;
    int c[] {0, 11111111, 22222222};
    int sum0 = pow(sum, m);
    for(int j = 0; j < 3; j ++)
    {
        int sum1 = sum0 + c[j];
        int d[5];
        for(int i = 0; i < 5; i++)
        {
            d[i] = (sum1 & 15) % 14;
            sum1 = sum1 >> 4;
        }
        std::cout << music[d[0]] << std::endl;
        std::cout << movies[d[1]] << std::endl;
        std::cout << actors[d[2]] << std::endl;
        std::cout << actriss[d[3]] << std::endl;
        std::cout << celeb[d[4]] << std::endl;
        std::cout << std::endl;
    }
}
