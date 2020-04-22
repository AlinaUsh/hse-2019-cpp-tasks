#include "doctest.h"
#include "CLI.h"


TEST_CASE ("ARCHIVING") {
    CLI args;
    int argc = 6;
    char *argv[6];
    argv[1] = (char *)"-c";
    argv[2] = (char *)"-f";
    argv[3] = (char *)"in.txt";
    argv[4] = (char *)"-o";
    argv[5] = (char *)"out.txt";
    args.parse(argc, argv);
            CHECK_EQ(args.input_file, argv[3]);
            CHECK_EQ(args.output_file, argv[5]);
            CHECK(!args.dearchiving);
            CHECK(args.archiving);
}

TEST_CASE ("DEARCHIVING") {
    CLI args;
    int argc = 6;
    char *argv[6];
    argv[1] = (char *)"-u";
    argv[2] = (char *)"-f";
    argv[3] = (char *)"in.txt";
    argv[4] = (char *)"-o";
    argv[5] = (char *)"out.txt";
    args.parse(argc, argv);
            CHECK_EQ(args.input_file, argv[3]);
            CHECK_EQ(args.output_file, argv[5]);
            CHECK(args.dearchiving);
            CHECK(!args.archiving);
}

TEST_CASE ("exception incorrect action") {
    bool fl = false;
    CLI args;
    int argc = 6;
    char *argv[6];
    argv[1] = (char *)"-t";
    argv[2] = (char *)"-f";
    argv[3] = (char *)"in.txt";
    argv[4] = (char *)"-o";
    argv[5] = (char *)"out.txt";
    try {
        args.parse(argc, argv);
    } catch (...) {
        fl = true;
    }
            CHECK(fl);
}

TEST_CASE ("2 actions") {
    bool fl = false;
    CLI args;
    int argc = 7;
    char *argv[7];
    argv[1] = (char *)"-c";
    argv[2] = (char *)"-f";
    argv[3] = (char *)"in.txt";
    argv[4] = (char *)"-o";
    argv[5] = (char *)"out.txt";
    argv[7] = (char *)"-u";
    try {
        args.parse(argc, argv);
    } catch (...) {
        fl = true;
    }
            CHECK(fl);
}

TEST_CASE ("no atcion") {
    bool fl = false;
    CLI args;
    int argc = 5;
    char *argv[5];
    argv[1] = (char*)"-f";
    argv[2] = (char *)"in.txt";
    argv[3] = (char *)"-o";
    argv[4] = (char *)"out.txt";
    try {
        args.parse(argc, argv);
    } catch (...) {
        fl = true;
    }
            CHECK(fl);
}

TEST_CASE ("no input file") {
    bool fl = false;
    CLI args;
    int argc = 6;
    char *argv[6];
    argv[1] = (char *)"-c";
    argv[2] = (char *)"-q";
    argv[3] = (char *)"in.txt";
    argv[4] = (char *)"-o";
    argv[5] = (char *)"out.txt";
    try {
        args.parse(argc, argv);
    } catch (...) {
        fl = true;
    }
            CHECK(fl);
}