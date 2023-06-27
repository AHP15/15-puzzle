#include <iostream>
#include <numeric>

class Tile
{
private:
  int m_number{};
public:
  Tile() = default;
  explicit Tile(int number): m_number{number}{};
  bool isEmpty() const{ return m_number == 0; };
  int getNum() const { return m_number; };

  friend std::ostream& operator<<(std::ostream& out, const Tile& t)
  {
    if (t.m_number > 9)
      out << " " << t.m_number << " ";
    else if (t.m_number > 0)
      out << "  " << t.m_number << " ";
    else if (t.m_number == 0)
      out << "    ";
    return out;
  };
};

constexpr int g_consoleLines{ 25 };

class Board
{
private:
  static constexpr int SIZE = 4;
  Tile m_tiles[SIZE][SIZE]{};
public:
  Board()
  {
    int i{0};
    for(int row{0}; row < SIZE; ++row)
    {
      for(int column{0}; column < SIZE; ++column)
      {
        ++i;
        m_tiles[row][column] = Tile{ i };

        if(i == 15) return;
      }
    }
  };

  friend std::ostream& operator<<(std::ostream& stream, const Board& board)
  {
    for(int i{0}; i < g_consoleLines; ++i)
    {
      stream << '\n';;
    }

    for(int row{0}; row < SIZE; ++row)
    {
      for(int column{0}; column < SIZE; ++column)
      {
        stream << board.m_tiles[row][column];
      }
      stream << '\n';
    }
    stream << '\n';

    return stream;
  };
};

namespace UserInput
{
  void ignoreLine()
  {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  char getCommand()
  {
    char input{};
    do {
      std::cin >> input;
      ignoreLine();
    }while (input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'q');
    return input;
  }
};

int main()
{
  Board board{};
  std::cout << board;

  while(true)
  {
    char command { UserInput::getCommand() };
    if(command == 'q') {
      std::cout << "\n\nBye!\n\n";
      break;
    } else {
      std::cout << "Valid command: " << command << '\n';
    }
  }
  return 0;
};