#include <bits/stdc++.h>

using namespace std;

enum AnimalType
{
    Dog,
    Cat
};

struct Animal
{
    string Name;
    AnimalType Type;
    unsigned short int Priority;
};

class Shelter
{
public:
    void Enqueue(Animal animal)
    {
        animal.Priority = ++count;

        if (animal.Type == AnimalType::Dog)
            dogs.push_back(animal);
        else if (animal.Type == AnimalType::Cat)
            cats.push_back(animal);
    }
    Animal DequeueAny()
    {
        Animal ret;
        if (dogs.empty() && cats.empty())
        {
            printf("Empty shelter");
            return ret;
        }

        if (dogs.empty() || cats.front().Priority < dogs.front().Priority)
        {
            ret = cats.front();
            cats.pop_front();
        }
        else
        {
            ret = dogs.front();
            dogs.pop_front();
        }

        return ret;
    }
    Animal DequeueDog()
    {
        Animal ret;
        if (dogs.empty())
        {
            printf("No dogs");
            return ret;
        }

        ret = dogs.front();
        dogs.pop_front();

        return ret;
    }
    Animal DequeueCat()
    {
        Animal ret;
        if (cats.empty())
        {
            printf("No dogs");
            return ret;
        }

        ret = cats.front();
        cats.pop_front();

        return ret;
    }
    bool IsEmpty()
    {
        return cats.empty() && dogs.empty();
    }

private:
    list<Animal> dogs, cats;
    unsigned short int count = 0;
};

int main()
{
    Shelter shelter;

    shelter.Enqueue(Animal{.Name = "Nico", .Type = AnimalType::Dog});
    shelter.Enqueue(Animal{.Name = "Ventania", .Type = AnimalType::Dog});
    shelter.Enqueue(Animal{.Name = "Garfield", .Type = AnimalType::Cat});
    shelter.Enqueue(Animal{.Name = "Cat2", .Type = AnimalType::Cat});
    shelter.Enqueue(Animal{.Name = "Snoopy dog", .Type = AnimalType::Dog});

    shelter.DequeueDog();
    while (!shelter.IsEmpty())
    {
        Animal a = shelter.DequeueAny();
        cout << "Got animal: " << a.Name << ", " << a.Type << endl;
    }
}