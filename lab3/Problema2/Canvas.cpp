#include "Canvas.h"
#include <cmath>
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)
{
    Width = width;
    Height = height;
    Matrix = new char* [Height];
    for (int i = 0; i < Height; i++)
    {
        Matrix[i] = new char [Width];
        for (int j = 0; j < Width; j++)
            Matrix[i][j] = ' ';
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j <= y + ray; j++)
            if (int(sqrt((i - x) * (i - x) + (j - y) * (j - y))) == ray)
                Matrix[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j <= y + ray; j++)
            if (int(sqrt((i - x) * (i - x) + (j - y) * (j - y))) < ray)
                Matrix[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = bottom; i <= top; i++)
    {
        Matrix[left][i] = ch;
        Matrix[right][i] = ch;
    }
    for (int i = left; i <= right; i++)
    {
        Matrix[i][bottom] = ch;
        Matrix[i][top] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = bottom; i <= top; i++)
        for (int j = left; j <= right; j++)
            Matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    Matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    if (x1 > y2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int D = 2 * dy - dx;
    int x = x1;
    int y = y1;
    while(x < y2)
    {
        if(D >= 0)
        {
            y++;
            D = D + 2 * dy - 2 * dx;
        }
        else
        {
            D = D + 2 * dy;
        }
        Matrix[x][y] = ch;
        x++;
    }
}

void Canvas::Print()
{
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
            cout << Matrix[i][j] << " ";
        cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Width; j++)
            Matrix[i][j] = ' ';
}