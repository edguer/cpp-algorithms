#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct coordinates
{
    unsigned short int x : 8;
    unsigned short int y : 8;
};

class image
{
public:
    image()
    {
        unsigned short int red = width;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j < red)
                    pixels[i][j] = 41;
                else
                    pixels[i][j] = 43;
            }
            red--;
        }

        pixels[2][20] = 45;
        pixels[2][21] = 45;
        pixels[2][22] = 45;
        pixels[3][22] = 45;
    }
    void print()
    {
        for (int i = 0; i < height; i++)
        {
            print_line(pixels[i], width);
        }
    }
    void paint_area(unsigned short int color, unsigned short int x, unsigned short int y)
    {
        if (y > height || x > width || y < 0 || x < 0)
        {
            cout << "Coordinates out of bound" << endl;
            return;
        }
        paint_area_stack(pixels[y][x], color, x, y);
    }

private:
    static const unsigned short int width = 100, height = 28;
    unsigned short int pixels[height][width] = {0};

    void print_block(unsigned short int color)
    {
        cout << "\e[0;" << color << ";97m ";
        cout << "\e[0m";
    }
    void print_line(unsigned short int *colors, unsigned int len)
    {
        for (unsigned int i = 0; i < len; i++)
        {
            print_block(colors[i]);
        }
        cout << endl;
    }
    void paint_area(unsigned short int original_color, unsigned short int new_color, unsigned short int x, unsigned short int y)
    {
        if (y < height && x < width && y >= 0 && x >= 0 && pixels[y][x] == original_color)
        {
            pixels[y][x] = new_color;
            paint_area(original_color, new_color, x + 1, y);
            paint_area(original_color, new_color, x - 1, y);
            paint_area(original_color, new_color, x, y + 1);
            paint_area(original_color, new_color, x, y - 1);
        }
    }
    void paint_area_stack(unsigned short int original_color, unsigned short int new_color, unsigned short int x, unsigned short int y)
    {
        coordinates initial_point{.x = x, .y = y};
        stack<coordinates> stack;
        stack.push(initial_point);

        while (!stack.empty())
        {
            coordinates point = stack.top();
            stack.pop();

            if (point.y < height && point.x < width && point.y >= 0 && point.x >= 0 && pixels[point.y][point.x] == original_color)
            {
                pixels[point.y][point.x] = new_color;
                stack.push(coordinates{ .x = (unsigned short int)(point.x + 1), .y = point.y });
                stack.push(coordinates{ .x = (unsigned short int)(point.x - 1), .y = point.y });
                stack.push(coordinates{ .x = point.x, .y = (unsigned short int)(point.y + 1) });
                stack.push(coordinates{ .x = point.x, .y = (unsigned short int)(point.y - 1) });
            }
        }
    }
};

int main()
{
    image i;
    i.print();
    i.paint_area(44, 0, 0);
    cout << "After painting: " << endl;
    i.print();
    i.paint_area(47, 99, 27);
    cout << "After painting: " << endl;
    i.print();
}