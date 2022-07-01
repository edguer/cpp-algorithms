#include <bits/stdc++.h>
using namespace std;

struct box
{
    unsigned short int height : 8;
    unsigned short int width : 8;
    unsigned short int depth : 8;
    unsigned short int volume()
    {
        return height * width * depth;
    }
    bool greater(box other)
    {
        return height > other.height && width > other.width && depth > other.depth;
    }
    void print()
    {
        cout << "height: " << height << ", width: " << width << ", depth:" << depth << ", volume: " << volume() << endl;
    }
};

void order(box *boxes, short int start, short int end)
{
    if (end > start)
    {
        short int low = start - 1;
        for (unsigned short int i = start; i < end; i++)
        {
            if (boxes[i].volume() < boxes[end].volume())
            {
                box temp = boxes[i];
                boxes[i] = boxes[++low];
                boxes[low] = temp;
            }
        }
        box temp = boxes[++low];
        boxes[low] = boxes[end];
        boxes[end] = temp;

        order(boxes, start, low - 1);
        order(boxes, low + 1, end);
    }
}

unsigned short int height(box *boxes, unsigned short int len)
{
    unsigned short h = 0;
    for (short int i = len - 1; i >= 0; i--)
    {
        h += boxes[i].height;
    }
    return h;
}

void print(box *boxes, unsigned short int len)
{
    for (short int i = len - 1; i >= 0; i--)
    {
        if (boxes[i].volume() > 0)
            boxes[i].print();
    }
}

box *highest(box *boxes, unsigned short int len)
{
    box *ret = new box[len]{NULL};
    vector<box*> compare;
    int count = 0;
    ret[count++] = boxes[len - 1];
    for (short int i = len - 2; i >= 0; i--)
    {
        if (ret[count - 1].greater(boxes[i]))
        {
            ret[count++] = boxes[i];
        }
        else
        {
            compare.push_back(highest(boxes, i + 1));
        }
    }

    for (auto it : compare)
    {
        if (height(it, len) > height(ret, len))
            ret = it;
    }

    return ret;
}

int main()
{
    box boxes[] = {
        box{.height = 5, .width = 1, .depth = 3},
        box{.height = 5, .width = 1, .depth = 5},
        box{.height = 1, .width = 1, .depth = 1}};
    unsigned short int len = sizeof(boxes) / sizeof(box);
    order(boxes, 0, len - 1);
    print(boxes, len);
    box *ret = highest(boxes, len);
    cout << "Result: " << endl;
    print(ret, len);
}