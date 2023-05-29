/**
 * Comments on the Game Lobby
 */

#include <iostream>
#include <string>

using namespace std;

class Player                                // Defines the Player class
{
public:                                     // The public material contained within the Player class
    Player(const string& name = "");        // Constructor that creates the player being passed a constant reference name being assigned as blank
    string GetName() const;                 // Constant string function GetNext is declared
    Player* GetNext() const;                // Constant Player pointer GetNext is declared
    void SetNext(Player* next);             // Void function SetNext is declared with passing the pointer Player* and string next
    
private:
    string m_Name;                          // String named m_Name is defined.
    Player* m_pNext;                        // Pointer is defined for the next player in the list
};

Player::Player(const string& name):         // When Player constuctor function is called and name is being defined as a constant reference
    m_Name(name),                           // m_Name is being passed the referenced name variable and assigning it to m_Name
    m_pNext(0)                              // Pointer m_pNext is being passed the value of zero
{}

string Player::GetName() const              // Public Player Function GetName is defined as a constant
{
    return m_Name;                          // Returns the value of n_Name
}

Player* Player::GetNext() const             // Pointer function for GetNext function inside Player class
{
    return m_pNext;                         // returns the address of the pointer
}

void Player::SetNext(Player* next)          // Void SetNext function inside Player class being passed the value of the Player pointer function and next.
{
    m_pNext = next;                         // m_pNext is now assigned the pointer address of "next"
}

class Lobby                                                             // Lobby class is defined.
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);
    
public:
    Lobby();                // Public constructor Lobby is declared
    ~Lobby();               // Public destructor Lobby is declared 
    void AddPlayer();       // void function AddPlayer is declared
    void RemovePlayer();    // void function RemovePlayer is declared
    void Clear();           // void function Clear is declared
    
private:
    Player* m_pHead;        // Player pointer points to m_pHead
};

Lobby::Lobby():             // Lobby constructor that creates a new "room" by creating a 0 in a new pointer string
    m_pHead(0)
{}

Lobby::~Lobby()             // Lobby destructor that calls the Clear function to remove all players from memory
{
    Clear();
}

void Lobby::AddPlayer()     // void function AddPlayer from Lobby class is defined.
{
    //create a new player node
    cout << "Please enter the name of the new player: ";
    string name;                                            // string name is created
    cin >> name;                                            // get player input and assign it to name
    Player* pNewPlayer = new Player(name);                  // Player* is called and creates a NEW player object in memory with the value of name

    //if list is empty, make head of list this new player
    if (m_pHead == 0)
    {
        m_pHead = pNewPlayer;                               // If the m_pHead pointer is pointing to the first address 0 then the first slot gets assigned the value of the NewPlayer pointer
    }
    //otherwise find the end of the list and add the player there
    else
    {
        Player* pIter = m_pHead;                            // If pointer m_pHead isn't pointing to the first position, pIter runs GetNext to move to the next sequential position from the previous value of m_pHead
        while (pIter->GetNext() != 0)
        {
            pIter = pIter->GetNext();       
        }
        pIter->SetNext(pNewPlayer);
    }
}

void Lobby::RemovePlayer()                                          // void function RemovePlayer from Lobby class is defined
{
    if (m_pHead == 0)                                               // Checks to make sure the pointer m_pHead isn't pointing at the first address
    {
        cout << "The game lobby is empty.  No one to remove!\n";
    }
    else
    {
        Player* pTemp = m_pHead;            // Pointer Player pTemp is assigned the address of m_pHead 
        m_pHead = m_pHead->GetNext();       // m_pHead is assigned the address of m_pHead after being ran through GetNext for the next position
        delete pTemp;                       // pTemp is then deleted from memory
    }
}

void Lobby::Clear()         // void function Clear embedded in Lobby class is defined
{
    while (m_pHead != 0)    // as long as the pointer isn't point to the first address run the RemovePlayer function
    {
        RemovePlayer();     // Calls RemovePlayer function to remove the player
    }
}

ostream& operator<<(ostream& os, const Lobby& aLobby)       // Using built in ostream commands, this function lists all the players contained in said lobby
{
    Player* pIter = aLobby.m_pHead;                 // Player* Iter is set to whatever the passed lobby name is and set to the m_pHead position

    os << "\nHere's who's in the game lobby:\n";
    if (pIter == 0)
    {
        os << "The lobby is empty.\n";
    }
    else
    {
        while (pIter != 0)
        {   
            os << pIter->GetName() << endl;     // the next position for pIter is displayed to the console
	        pIter = pIter->GetNext();           // pIter is then assigned the address of the next position.
        }
    }

    return os;
}

int main()
{
    Lobby myLobby;
    int choice;
    
    do
	{
	    cout << myLobby;
        cout << "\nGAME LOBBY\n";
        cout << "0 - Exit the program.\n";
        cout << "1 - Add a player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the lobby.\n";
        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 0: cout << "Good-bye.\n"; break;
	        case 1: myLobby.AddPlayer(); break;  
            case 2: myLobby.RemovePlayer(); break;
            case 3: myLobby.Clear(); break;
            default: cout << "That was not a valid choice.\n";
        }
	}
    while (choice != 0);
    
    return 0;
}
