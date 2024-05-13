#include <iostream>
#include <string>
#include <vector>

class SocialNetwork {
public:
    struct Human {
        std::string name;
        int id;

        Human(const std::string& _name, int _id) : name(_name), id(_id) {}
    };

private:
    std::vector<Human> people;
    std::vector<std::vector<bool>> friendMatrix;

public:

    void addPerson(const std::string& name, int id) {
        for (const auto& person : people) {
            if (person.name == name || person.id == id) {
                std::cout << "Person with this id or name already exists.\n";
                return;
            }
        }
        people.emplace_back(name, id);
        updateMatrixSize();
        std::cout << "Person " << name << " added to the network.\n";
    }

    void updateMatrixSize() {
        size_t newSize = people.size();
        std::vector<std::vector<bool>> newMatrix(newSize, std::vector<bool>(newSize, false));
        for (size_t i = 0; i < newSize; ++i) {
            for (size_t j = 0; j < newSize; ++j) {
                if (i < friendMatrix.size() && j < friendMatrix[i].size()) {
                    newMatrix[i][j] = friendMatrix[i][j];
                }
            }
        }
        friendMatrix = std::move(newMatrix);
    }

    bool personExistsWithName(const std::string& name) const {
        for (const auto& person : people) {
            if (person.name == name)
                return true;
        }
        return false;
    }

    bool personExistsWithId(int id) const {
        for (const auto& person : people) {
            if (person.id == id)
                return true;
        }
        return false;
    }

    void printAllPeople() const {
        std::cout << "List of people in network:\n";
        for (const auto& person : people) {
            std::cout << "Name: " << person.name << ", ID: " << person.id << std::endl;
        }
    }

    void removePersonByName(const std::string& name) {
        for (auto it = people.begin(); it != people.end(); ++it) {
            if (it->name == name) {
                int index = it - people.begin();
                people.erase(it);
                friendMatrix.erase(friendMatrix.begin() + index);
                for (auto& row : friendMatrix)
                    row.erase(row.begin() + index);

                updateMatrixSize();
                std::cout << "Person " << name << " been removed from network.\n";
                return;
            }
        }
        std::cout << "Person " << name << " wasn't found.\n";
    }

    void removePersonById(int id) {
        for (auto it = people.begin(); it != people.end(); ++it) {
            if (it->id == id) {
                int index = it - people.begin();
                std::string name = it->name;
                people.erase(it);
                friendMatrix.erase(friendMatrix.begin() + index);
                for (auto& row : friendMatrix)
                    row.erase(row.begin() + index);

                updateMatrixSize();
                std::cout << "Person " << name << " removed from network.\n";
                return;
            }
        }
        std::cout << "Person with id: " << id << " - not found.\n";
    }

    void printFriendsUpToTwoHandshakes(int id) const {
        if (!personExistsWithId(id)) {
            std::cout << "Person with id: " << id << " - not found.\n";
            return;
        }

        std::cout << "Friends of " << people[id].name << " to 2 handshakes:\n";
        for (size_t i = 0; i < friendMatrix.size(); ++i) {
            if (friendMatrix[id][i]) {
                std::cout << "- " << people[i].name << std::endl;
                for (size_t j = 0; j < friendMatrix[i].size(); ++j) {
                    if (friendMatrix[i][j] && j != id) {
                        std::cout << "  - " << people[j].name << std::endl;
                    }
                }
            }
        }
    }

    void addFriendship(int id1, int id2) {
        if (!personExistsWithId(id1) || !personExistsWithId(id2)) {
            std::cout << "One or both persons not found in network.\n";
            return;
        }
        if (id1 == id2) {
            std::cout << "Cannot establish friendship with oneself.\n";
            return;
        }
        if (friendMatrix[id1][id2]) {
            std::cout << "Friendship between " << people[id1].name << " and " << people[id2].name << " already exists.\n";
            return;
        }
        friendMatrix[id1][id2] = true;
        friendMatrix[id2][id1] = true;
        std::cout << "Friendship between " << people[id1].name << " and " << people[id2].name << " been added.\n";
    }

    void removeFriendship(int id1, int id2) {
        if (!personExistsWithId(id1) || !personExistsWithId(id2)) {
            std::cout << "One or both persons not found in network.\n";
            return;
        }
        if (!friendMatrix[id1][id2]) {
            std::cout << "There is no friendship between " << people[id1].name << " and " << people[id2].name << ".\n";
            return;
        }
        friendMatrix[id1][id2] = false;
        friendMatrix[id2][id1] = false;
        std::cout << "Friendship between " << people[id1].name << " and " << people[id2].name << " been removed.\n";
    }

    void printNameById(int id) const {
        for (const auto& person : people) {
            if (person.id == id) {
                std::cout << "Name of person with id " << id << ": " << person.name << std::endl;
                return;
            }
        }
        std::cout << "Person with id " << id << " not found in the network.\n";
    }
};
