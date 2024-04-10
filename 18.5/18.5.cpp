#include <iostream>

class Player
{
private:
    int score;
    std::string name;
public:
    Player(std::string _name, int _score) : name(_name), score(_score)
    {}
    std::string Name()
    {
        return name;
    }
    int Score()
    {
        return score;
    }


};

int main()
{
     std::cout << "Number of Player(s): ";
     int plnu;
     std::cin >> plnu;

     Player** p = new Player * [plnu]; // вот тут. почему именно так?

     for (auto i = 0; i < plnu; i++)
     {
         std::cout << "Enter Player Name: ";
         std::string name;
         std::cin >> name;

         std::cout << "Enter Scores: ";
         int sc = 0;
         std::cin >> sc;

         p[i] = new Player(name, sc); // тут подсказал чат gpt, можете сказать почему именно так, а не через p[i]-> ?(если бы там был допустим функция SetName или SetScore)
     }
     
     std::cout << std::endl;

     for (auto i = 0; i < plnu; i++)
     {
         for (auto j = i + 1; j < plnu; j++)
         {
             if ((p[i]->Score()) <= (p[j]->Score()))
             {
                 Player* temp = p[i];
                 p[i] = p[j];
                 p[j] = temp;
             }
         }
     }

     for (auto i = 0; i < plnu; i++)
     {
        std::cout << "Player Name: " << p[i]->Name() << '\n';
        std:: cout << "Score: " << p[i]->Score() << '\n' << '\n';
     }



     for (auto i = 0; i < plnu; ++i) 
     {  // тут тоже подсказал нейронка, но почему по отделности надо все удалять, если есть delete[] ??
         delete p[i];
     }
     delete[] p;
}
