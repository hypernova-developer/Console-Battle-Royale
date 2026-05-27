/*
MIT License

Copyright (c) 2026 hypernova-developer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void SleepForMilliSeconds(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void PrintStatus(int &turn, string p1, unsigned int h1, string p2, unsigned int h2)
{
    cout << "\n==========================================" << endl;
    cout << "Turn: " << turn << endl;
    cout << p1 << " [HP: " << h1 << "]  vs  " << p2 << " [HP: " << h2 << "]" << endl;
    cout << "==========================================" << endl;
}

bool IsHealth_0(unsigned int health)
{
    if (health == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InitGame()
{
    const string dev_name = "hypernova-developer";
    const unsigned int release_year = 2026;
    const unsigned int max_health = 1000;
    int turn = 1;

    cout << "============ Console Battle Royale ============" << endl;
    SleepForMilliSeconds(500);
    cout << "Dev: " << dev_name << endl;
    SleepForMilliSeconds(500);
    cout << "Development Year: " << release_year << endl;
    SleepForMilliSeconds(500);

    string name1;
    unsigned int health_point1 = max_health;
    int choice1;
    bool p1_ultimate_used = false;

    string name2;
    unsigned int health_point2 = max_health;
    int choice2;
    bool p2_ultimate_used = false;

    cout << "\nEnter Player 1 Name: ";
    cin >> name1;
    cout << "Enter Player 2 Name: ";
    cin >> name2;

    cout << "\n--- BATTLE STARTS! ---" << endl;
    SleepForMilliSeconds(1000);

    while (!IsHealth_0(health_point1) && !IsHealth_0(health_point2))
    {
        PrintStatus(turn, name1, health_point1, name2, health_point2);

        cout << name1 << "'s Turn! Choose Action:\n\t1: Attack\n\t2: Defense\n\t3: Ultimate (" 
             << (p1_ultimate_used ? "0" : "1") << " left)\nChoice: ";
        cin >> choice1;

        cout << name2 << "'s Turn! Choose Action:\n\t1: Attack\n\t2: Defense\n\t3: Ultimate (" 
             << (p2_ultimate_used ? "0" : "1") << " left)\nChoice: ";
        cin >> choice2;

        if (choice1 == 3)
        {
            if (p1_ultimate_used)
            {
                cout << "\n[!] " << name1 << " tried to spam ULTIMATE but failed! Turn wasted!" << endl;
                choice1 = 0;
            }
            else
            {
                p1_ultimate_used = true;
            }
        }

        if (choice2 == 3)
        {
            if (p2_ultimate_used)
            {
                cout << "\n[!] " << name2 << " tried to spam ULTIMATE but failed! Turn wasted!" << endl;
                choice2 = 0;
            }
            else
            {
                p2_ultimate_used = true;
            }
        }

        cout << "\n--- Round Results ---" << endl;
        SleepForMilliSeconds(500);

        if (choice1 == 1)
        {
            if (choice2 == 2)
            {
                cout << name2 << " blocked " << name1 << "'s attack! Reduced damage to 50!" << endl;
                health_point2 = (health_point2 > 50) ? (health_point2 - 50) : 0;
            }
            else
            {
                cout << name1 << " attacked for 150 damage!" << endl;
                health_point2 = (health_point2 > 150) ? (health_point2 - 150) : 0;
            }
        }
        else if (choice1 == 3)
        {
            cout << name1 << " unleashed ULTIMATE for 300 massive damage!" << endl;
            health_point2 = (health_point2 > 300) ? (health_point2 - 300) : 0;
        }
        else if (choice1 == 2 && choice2 != 1)
        {
            cout << name1 << " prepared for defense but no attack came!" << endl;
        }

        if (!IsHealth_0(health_point2)) 
        {
            if (choice2 == 1)
            {
                if (choice1 == 2)
                {
                    cout << name1 << " blocked " << name2 << "'s attack! Reduced damage to 50!" << endl;
                    health_point1 = (health_point1 > 50) ? (health_point1 - 50) : 0;
                }
                else
                {
                    cout << name2 << " attacked for 150 damage!" << endl;
                    health_point1 = (health_point1 > 150) ? (health_point1 - 150) : 0;
                }
            }
            else if (choice2 == 3)
            {
                cout << name2 << " unleashed ULTIMATE for 300 massive damage!" << endl;
                health_point1 = (health_point1 > 300) ? (health_point1 - 300) : 0;
            }
            else if (choice2 == 2 && choice1 != 1)
            {
                cout << name2 << " prepared for defense but no attack came!" << endl;
            }
        }

        SleepForMilliSeconds(1000);
        turn++;
    }

    cout << "\n==========================================" << endl;
    cout << "               GAME OVER                  " << endl;
    cout << "==========================================" << endl;

    if (IsHealth_0(health_point1)) 
    {
        cout << "Winner is: " << name2 << "! " << endl;
    } 
    else 
    {
        cout << "Winner is: " << name1 << "! " << endl;
    }
}

int main()
{
    InitGame();
    return 0;
}
