#include <json/json.h>
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
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(buffer, root);
    auto end_parse = std::chrono::high_resolution_clock::now();

    if (!parsingSuccessful) {
        std::cerr << "Error while parsing JSON." << std::endl;
        return 1;
    }

    auto start_modify = std::chrono::high_resolution_clock::now();
    for (Json::Value& item : root) {
        item["_id"] = item["_id"].asString() + " modified";
        item["guid"] = item["guid"].asString() + " modified";
        item["isActive"] = !item["isActive"].asBool();
        item["balance"] = item["balance"].asString() + " modified";
        item["picture"] = item["picture"].asString() + " modified";
        item["age"] = item["age"].asInt() + 1;
        item["eyeColor"] = item["eyeColor"].asString() + " modified";
        item["name"] = item["name"].asString() + " modified";
        item["gender"] = item["gender"].asString() + " modified";
        item["company"] = item["company"].asString() + " modified";
        item["email"] = item["email"].asString() + " modified";
        item["phone"] = item["phone"].asString() + " modified";
        item["address"] = item["address"].asString() + " modified";
        item["about"] = item["about"].asString() + " modified";
        item["registered"] = item["registered"].asString() + " modified";
        item["latitude"] = item["latitude"].asDouble() + 1.0;
        item["longitude"] = item["longitude"].asDouble() + 1.0;

        for (Json::Value& tag : item["tags"]) {
            tag = tag.asString() + " modified";
        }

        for (Json::Value& friendObj : item["friends"]) {
            friendObj["name"] = friendObj["name"].asString() + " modified";
        }

        item["greeting"] = item["greeting"].asString() + " modified";
        item["favoriteFruit"] = item["favoriteFruit"].asString() + " modified";
    }
    auto end_modify = std::chrono::high_resolution_clock::now();

    auto start_write = std::chrono::high_resolution_clock::now();
    std::ofstream outputFileStream("output_jsoncpp.json");
    Json::StreamWriterBuilder builder;
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(root, &outputFileStream);
    auto end_write = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> read_duration = end_read - start_read;
    std::chrono::duration<double, std::milli> parse_duration = end_parse - start_parse;
    std::chrono::duration<double, std::milli> modify_duration = end_modify - start_modify;
    std::chrono::duration<double, std::milli> write_duration = end_write - start_write;

    std::cout << "JsonCpp Read time: " << read_duration.count() << " ms\n";
    std::cout << "JsonCpp Parse time: " << parse_duration.count() << " ms\n";
    std::cout << "JsonCpp Modify time: " << modify_duration.count() << " ms\n";
    std::cout << "JsonCpp Write time: " << write_duration.count() << " ms\n";

    system("pause");
}