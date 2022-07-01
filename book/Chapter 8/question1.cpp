#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * Card: rank, suit
 * Player: cards
 * Dealer:Player:
 * Shoe: cards
 * */

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
        build(decks);
    }
    void shuffle()
    {
        srand(time(NULL));
        for (unsigned short int i = count - 1; i > 0; i--)
        {
            unsigned short int j = rand() % (i + 1);
            card *temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << cards[i]->suit_name() << "-" << cards[i]->rank_name() << endl;
        }
    }
    card *push_top()
    {
        card *ret = cards[--count];
        cards[count] = NULL;
        return ret;
    }

private:
    card **cards = NULL;
    unsigned short int count = 0;
    void build(unsigned short int decks)
    {
        cards = new card *[decks * 52];
        for (unsigned short int i = 0; i < decks; i++)
        {
            build_deck();
        }
        shuffle();
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

class player
{
public:
    player()
    {
    }
    player(string name)
    {
        _name = name;
    }
    unsigned short int receive(card *_card, bool visible)
    {
        card new_card(_card->rank(), _card->suit());
        new_card.visible(visible);
        cards[count++] = new_card;

        cout << _name << " received a " << new_card.rank_name() << " of " << new_card.suit_name() << ", count " << count << endl;

        return sum();
    }
    moves play()
    {
        cout << "Player " << _name << " turn (stand(1) or hit(2)): ";
        unsigned short int result = 0;
        cin >> result;
        return static_cast<moves>(result);
    }
    string name()
    {
        return _name;
    }
    void show_cards()
    {
        cout << "Player " << _name << " cards: ";
        for (unsigned short int i = 0; i < count; i++)
        {
            if (cards[i].visible())
            {
                cout << cards[i].rank_name() << "(v) ";
            }
            else
            {
                cout << cards[i].rank_name() << "(h) ";
            }
        }
        cout << endl;
    }
    unsigned short int sum()
    {
        card *aces = new card[10];
        unsigned short int aces_count = 0;
        unsigned short int sum = 0;
        for (unsigned short int i = 0; i < count; i++)
        {
            if (cards[i].rank() == ranks::ace)
                aces[aces_count++] = cards[i];
            else
                sum += (unsigned short int)cards[i].rank() >= 10 ? 10 : (unsigned short int)cards[i].rank();
        }

        for (unsigned short int i = 0; i < aces_count; i++)
        {
            if (sum <= 10)
                sum += 11;
            else
                sum++;
        }
        cout << _name << ": " << sum << endl;
        return sum;
    }

private:
    card *cards = new card[INT8_MAX];
    string _name;
    unsigned short int count = 0;
};

class dealer : public player
{
public:
    dealer(shoe *shoe) : player("Dealer")
    {
        _shoe = shoe;
    }
    bool start(player *_players, unsigned short int player_count)
    {
        give_card(this, true);
        if (give_card(this, false) == 21)
        {
            cout << this->name() << " made 21, he/she wins the game!" << endl;
            return true;
        }
        this->show_cards();

        for (size_t i = 0; i < player_count; i++)
        {
            give_card(&_players[i], true);
            if (give_card(&_players[i], false) == 21)
            {
                cout << _players[i].name() << " made 21, he/she wins the game!" << endl;
                return true;
            }
            _players[i].show_cards();
        }

        return false;
    }
    unsigned short int give_card(player *current_player, bool visible)
    {
        return current_player->receive(_shoe->push_top(), true);
    }
    bool round(player *_players, unsigned short int player_count)
    {
        while (this->sum() <= 17)
        {
            if (give_card(this, false) == 21)
            {
                cout << this->name() << " made 21, he/she wins the game!" << endl;
                return true;
            } 
            else if (this->sum() > 21)
            {
                cout << this->name() << " busted!";
            }
        }
        this->show_cards();

        for (size_t i = 0; i < player_count; i++)
        {
            while (_players[i].play() == moves::hit)
            {
                if (give_card(&_players[i], false) == 21)
                {
                    cout << _players[i].name() << " made 21, he/she wins the game!" << endl;
                    return true;
                } 
                else if (_players[i].sum() > 21)
                {
                    cout << _players[i].name() << " busted!";
                }
            }
            _players[i].show_cards();
        }

        return false;
    }
    void finish(player *_players, unsigned short int player_count)
    {
        cout << "Game ended: " << endl;
        for (size_t i = 0; i < player_count; i++)
        {
            cout << _players[i].name() << ": " << _players[i].sum() << endl;
        }
    }

private:
    shoe *_shoe;
};

class game
{
public:
    game(string *players, unsigned short int num_players, unsigned short int decks)
    {
        _player_count = num_players;
        _players = new player[_player_count];
        _shoe = new shoe(decks);
        for (unsigned short int i = 0; i < _player_count; i++)
        {
            _players[i] = player(players[i]);
            cout << players[i] << " is in the game!" << endl;
        }
        _dealer = new dealer(this->get_shoe());
    }
    shoe *get_shoe()
    {
        return _shoe;
    }
    void print()
    {
        for (unsigned short int i = 0; i < _player_count; i++)
        {
            cout << _players[i].name() << endl;
        }
    }
    void start()
    {
        if (!_dealer->start(_players, _player_count) && !_dealer->round(_players, _player_count))
            _dealer->finish(_players, _player_count);
    }

private:
    dealer *_dealer;
    player *_players;
    shoe *_shoe;
    unsigned short int _player_count;
};

int main()
{
    string players[] = {"Eduardo", "Nico", "Natália"};
    game blackjack(players, 3, 1);

    blackjack.start();
}