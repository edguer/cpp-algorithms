#include <bits/stdc++.h>
#include <iostream>
#include <random>

using namespace std;

std::random_device rd;                         // obtain a random number from hardware
std::mt19937 gen(rd());                        // seed the generator
std::uniform_int_distribution<> distr(0, 51); // define the range

enum suits
{
    clubs,
    diamonds,
    hearts,
    spades
};

enum ranks
{
    ace = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13
};

enum moves
{
    stand,
    hit
};

class card
{
public:
    card()
    {
    }
    card(ranks rank, suits suit)
    {
        _rank = rank;
        _suit = suit;
    }
    ranks rank()
    {
        return _rank;
    }
    string rank_name()
    {
        switch (_rank)
        {
        case ranks::ace:
            return "ace";
            break;
        case ranks::two:
            return "two";
            break;
        case ranks::three:
            return "three";
            break;
        case ranks::four:
            return "four";
            break;
        case ranks::five:
            return "five";
            break;
        case ranks::six:
            return "six";
            break;
        case ranks::seven:
            return "seven";
            break;
        case ranks::eight:
            return "eight";
            break;
        case ranks::nine:
            return "nine";
            break;
        case ranks::ten:
            return "ten";
            break;
        case ranks::jack:
            return "jack";
            break;
        case ranks::queen:
            return "queen";
            break;
        case ranks::king:
            return "king";
            break;
        default:
            return "";
            break;
        }
    }
    suits suit()
    {
        return _suit;
    }
    string suit_name()
    {
        switch (_suit)
        {
        case suits::clubs:
            return "clubs";
            break;
        case suits::diamonds:
            return "diamonds";
            break;
        case suits::hearts:
            return "hearts";
            break;
        case suits::spades:
            return "spades";
            break;
        default:
            return "";
            break;
        }
    }
    bool visible()
    {
        return _visible;
    }
    void visible(bool is_visible)
    {
        _visible = is_visible;
    }

private:
    ranks _rank;
    suits _suit;
    bool _visible = false;
};

class shoe
{
public:
    shoe(unsigned short int decks)
    {
        this->decks = decks;
        build(decks);
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << cards[i]->suit_name() << "-" << cards[i]->rank_name() << endl;
        }
    }
    void shuffle()
    {
        for (unsigned short int i = 0; i < count; i++)
        {
            unsigned short int dest = distr(gen) * decks;
            swap(cards[i], cards[dest]);
        }
    }

private:
    card **cards = NULL;
    unsigned short int count = 0, decks = 0;
    void build(unsigned short int decks)
    {
        cards = new card *[decks * 52];
        for (unsigned short int i = 0; i < decks; i++)
        {
            build_deck();
        }
    }
    void build_deck()
    {
        for (suits suit = suits::clubs; suit <= suits::spades; suit = suits(suit + 1))
        {
            for (ranks rank = ranks::ace; rank <= ranks::king; rank = ranks(rank + 1))
            {
                cards[count++] = new card(rank, suit);
            }
        }
    }
};

int main()
{
    shoe s(1);
    s.print();
    s.shuffle();
    cout << "--------" << endl << endl;
    s.print();
}