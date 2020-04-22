#include <iostream>
#include <sstream>

#include "doctest.h"
#include "HuffmanArchiver.h"

TEST_CASE ("HuffmanArchiver") {
    std::ofstream of("input.txt");
    std::string start_string;
    start_string = "a!@#$%^&*()_{:OUKYT\n\nsadefgtrhn\na\0efrtgyhujik34565y";

    of << start_string;
    of.close();

    HuffmanArchiver archiver;
    std::ifstream in;
    std::ofstream out;

    in = std::ifstream(static_cast<std::string>("input.txt"), std::ifstream::in);
    out = std::ofstream(static_cast<std::string>("output.txt"));

    archiver.createArchive(in, out);

    in.close();
    out.close();

    std::ifstream in1("output.txt");
    std::ofstream out1("decode_result.txt");

    archiver.unpackArchive(in1, out1);

    in1.close();
    out1.close();

    std::ifstream ifs("decode_result.txt");
    std::string res = "";
    while (ifs) {
        char c = ifs.get();
        if (c != EOF) {
            res += c;
        } else {
            break;
        }
    }
    ifs.close();
            CHECK_EQ(res, start_string);
}

TEST_CASE ("HuffmanArchiver") {
    std::ofstream of("input2.txt");
    std::string start_string;
    SUBCASE ("2 lines") {
        start_string = "a\na";
    }
    of << start_string;
    of.close();

    HuffmanArchiver archiver;
    std::ifstream in;
    std::ofstream out;

    in = std::ifstream(static_cast<std::string>("input2.txt"), std::ifstream::in);
    out = std::ofstream(static_cast<std::string>("output2.txt"));

    archiver.createArchive(in, out);

    in.close();
    out.close();

    std::ifstream in1("output2.txt");
    std::ofstream out1("decode_result2.txt");

    archiver.unpackArchive(in1, out1);

    in1.close();
    out1.close();

    std::ifstream ifs("decode_result2.txt");
    std::string res = "";
    while (ifs) {
        char c = ifs.get();
        if (c != EOF) {
            res += c;
        } else {
            break;
        }
    }
    ifs.close();
            CHECK_EQ(res, start_string);
}

TEST_CASE ("HuffmanArchiver") {
    std::ofstream of("input3.txt");
    std::string start_string;
    SUBCASE ("empty file") {
        start_string = "";
    }
    of << start_string;
    of.close();

    HuffmanArchiver archiver;
    std::ifstream in;
    std::ofstream out;

    in = std::ifstream(static_cast<std::string>("input3.txt"), std::ifstream::in);
    out = std::ofstream(static_cast<std::string>("output3.txt"));

    archiver.createArchive(in, out);

    in.close();
    out.close();

    std::ifstream in1("output3.txt");
    std::ofstream out1("decode_result3.txt");

    archiver.unpackArchive(in1, out1);

    in1.close();
    out1.close();

    std::ifstream ifs("decode_result3.txt");
    std::string res = "";
    while (ifs) {
        char c = ifs.get();
        if (c != EOF) {
            res += c;
        } else {
            break;
        }
    }
    ifs.close();
            CHECK_EQ(res, start_string);
}