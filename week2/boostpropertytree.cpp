#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <cstdlib>

int main() {
    auto start_read = std::chrono::high_resolution_clock::now();
    std::ifstream file("generated.json");
    std::stringstream buffer;
    buffer << file.rdbuf();
    auto end_read = std::chrono::high_resolution_clock::now();

    auto start_parse = std::chrono::high_resolution_clock::now();
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(buffer, pt);
    auto end_parse = std::chrono::high_resolution_clock::now();

    auto start_modify = std::chrono::high_resolution_clock::now();
    for (auto& item : pt) {
        item.second.put("_id", item.second.get<std::string>("_id") + " modified");
        item.second.put("guid", item.second.get<std::string>("guid") + " modified");
        item.second.put("balance", item.second.get<std::string>("balance") + " modified");
        item.second.put("picture", item.second.get<std::string>("picture") + " modified");
        item.second.put("eyeColor", item.second.get<std::string>("eyeColor") + " modified");
        item.second.put("name", item.second.get<std::string>("name") + " modified");
        item.second.put("gender", item.second.get<std::string>("gender") + " modified");
        item.second.put("company", item.second.get<std::string>("company") + " modified");
        item.second.put("email", item.second.get<std::string>("email") + " modified");
        item.second.put("phone", item.second.get<std::string>("phone") + " modified");
        item.second.put("address", item.second.get<std::string>("address") + " modified");
        item.second.put("about", item.second.get<std::string>("about") + " modified");
        item.second.put("registered", item.second.get<std::string>("registered") + " modified");
        item.second.put("latitude", item.second.get<double>("latitude") + 1.0);
        item.second.put("longitude", item.second.get<double>("longitude") + 1.0);
        item.second.put("isActive", !item.second.get<bool>("isActive"));
        item.second.put("age", item.second.get<int>("age") + 1);

        for (auto& tag : item.second.get_child("tags")) {
            tag.second.data() = tag.second.get_value<std::string>() + " modified";
        }

        for (auto& friendObj : item.second.get_child("friends")) {
            friendObj.second.put("name", friendObj.second.get<std::string>("name") + " modified");
        }

        item.second.put("greeting", item.second.get<std::string>("greeting") + " modified");
        item.second.put("favoriteFruit", item.second.get<std::string>("favoriteFruit") + " modified");
    }
    auto end_modify = std::chrono::high_resolution_clock::now();

    auto start_write = std::chrono::high_resolution_clock::now();
    std::ofstream outputFileStream("output_boost.json");
    boost::property_tree::write_json(outputFileStream, pt);
    auto end_write = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> read_duration = end_read - start_read;
    std::chrono::duration<double, std::milli> parse_duration = end_parse - start_parse;
    std::chrono::duration<double, std::milli> modify_duration = end_modify - start_modify;
    std::chrono::duration<double, std::milli> write_duration = end_write - start_write;

    std::cout << "Boost Property Tree Read time: " << read_duration.count() << " ms\n";
    std::cout << "Boost Property Tree Parse time: " << parse_duration.count() << " ms\n";
    std::cout << "Boost Property Tree Modify time: " << modify_duration.count() << " ms\n";
    std::cout << "Boost Property Tree Write time: " << write_duration.count() << " ms\n";

    system("pause");
}