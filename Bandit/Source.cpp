#include <iostream>
#include <ctime>
using namespace std;

class Queue
{
    int* Wait;
    int MaxQueueLength;
    int QueueLength;

public:
    Queue(int maxQueueLength);
    ~Queue();
    void Add(int c);
    int Extract();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Show();
};

void Queue::Show()
{
    cout << "\n-------------------------------------\n";
    for (int i = 0; i < QueueLength; i++)
    {
        cout << Wait[i] << " ";
    }
    cout << "\n-------------------------------------\n";
}

Queue::~Queue()
{
    delete[] Wait;
}

void Queue::Clear()
{
    QueueLength = 0;
}

bool Queue::IsEmpty()
{
    return QueueLength == 0;
}

bool Queue::IsFull()
{
    return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
    return QueueLength;
}

void Queue::Add(int c)
{
    if (!IsFull())
        Wait[QueueLength++] = c;
}

int Queue::Extract()
{
    if (!IsEmpty())
    {
        int temp = Wait[0];
        for (int i = 0; i < QueueLength - 1; i++)
        {
            Wait[i] = Wait[i + 1];
        }
        Wait[QueueLength - 1] = temp;
        return temp;
    }
    return -1;
}

Queue::Queue(int count1)
{
    MaxQueueLength = count1;
    Wait = new int[MaxQueueLength];
    for (int i = 0; i < MaxQueueLength; i++)
    {
        Wait[i] = i + 1;
    }
    QueueLength = MaxQueueLength;
}

int main()
{
    srand(time(0));

    Queue slotMachine1(3);
    Queue slotMachine2(3);
    Queue slotMachine3(3);
    char spinButton;

    int result1;
    int result2;
    int result3;

    int spins1;
    int spins2;
    int spins3;

    int WIN = 0;
    int money = 20;

    while (true)
    {
        cout << "Money: " << money << endl;
        if (money <= 0)
        {
            break;
        }
        cout << "Press 'g' to spin the reels or 'q' to quit: ";
        cin >> spinButton;

        if (spinButton == 'q')
        {
            cout << "Exiting the game. Thanks for playing!" << endl;
            break;
        }
        else if (spinButton == 'g')
        {
            money -= 1;
            spins1 = rand() % 5 + 1;
            spins2 = rand() % 5 + 1;
            spins3 = rand() % 5 + 1;

            for (int i = 0; i < spins1; i++)
            {
                slotMachine1.Extract();
            }
            for (int i = 0; i < spins2; i++)
            {
                slotMachine2.Extract();
            }
            for (int i = 0; i < spins3; i++)
            {
                slotMachine3.Extract();
            }

            cout << "Spinning..." << endl;
            cout << "Result: ";

            result1 = slotMachine1.Extract();
            result2 = slotMachine2.Extract();
            result3 = slotMachine3.Extract();

            cout << result1 << " | " << result2 << " | " << result3 << endl;

            if (result1 == result2 && result2 == result3)
            {
                cout << "You win!" << endl;
                WIN++;
                money += 10;
            }
            else
            {
                cout << "Loss" << endl;
            }
        }
    }
    cout << "You win: " << WIN << endl;

    return 0;
}