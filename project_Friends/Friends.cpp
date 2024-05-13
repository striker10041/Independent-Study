#include <iostream>
#include "SocialNetwork.h"
using namespace std;

int main() {
    SocialNetwork network;

    // Add some people to the network
    network.addPerson("Alice", 1);
    network.addPerson("Bob", 2);
    network.addPerson("Charlie", 3);
    network.addPerson("David", 4);
    network.addPerson("Eve", 5);
    
    // Print name by id
    network.printNameById(1);

    // Print all people in the network
    network.printAllPeople();
    cout << endl;

    // Check if a person with a certain name and id exists
    std::cout << "Is there a person Alice: " << std::boolalpha << network.personExistsWithName("Alice") << std::endl;
    std::cout << "Is there a person with id 2 in the network: " << std::boolalpha << network.personExistsWithId(2) << std::endl;
    cout << endl;

    // Remove a person from the network by name and by id
    network.removePersonByName("Charlie");
    network.removePersonById(4);
    cout << endl;

    // Print all people in the network after removal
    network.printAllPeople();
    cout << endl;

    // Add friendships between people
    network.addFriendship(1, 2);
    network.addFriendship(3, 5);
    network.addFriendship(3, 5);
    cout << endl;
    // Print all friends within 2 handshakes for a specific person
    network.printFriendsUpToTwoHandshakes(1);

    return 0;
}
