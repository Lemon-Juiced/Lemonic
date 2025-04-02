#include "Interop.h"
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Runs a C program and returns the output as a string.
 * 
 * @param isFile Indicates whether the input is a file or a string.
 * @param input The C program to run, either as a file path or as a string.
 * @return The output of the C program as a string.
 */
string Interop::runC(bool isFile, string input) {
    string command = "";
    string outputFile = "temp_output.txt";

    #ifdef _WIN32
        if (isFile) {
            command = "gcc " + input + " -o output.exe && output.exe > " + outputFile;
        } else {
            command = "echo \"" + input + "\" | gcc -x c -o output.exe - && output.exe > " + outputFile;
        }
    #else
        if (isFile) {
            command = "gcc " + input + " -o output && ./output > " + outputFile;
        } else {
            command = "echo \"" + input + "\" | gcc -x c -o output - && ./output > " + outputFile;
        }
    #endif

    // Execute the command
    int result = system(command.c_str());
    if (result != 0) {
        return "Error: Command execution failed.";
    }

    // Read the output from the temporary file
    ifstream outputFileStream(outputFile);
    if (!outputFileStream.is_open()) {
        return "Error: Unable to read output.";
    }

    string output((istreambuf_iterator<char>(outputFileStream)), istreambuf_iterator<char>());
    outputFileStream.close();

    // Clean up temporary files
    remove(outputFile.c_str());
    #ifdef _WIN32
        remove("output.exe");
    #else
        remove("output");
    #endif

    return output;
}

/**
 * Runs a shell command and returns the output as a string.
 * 
 * @param isFile Indicates whether the input is a file or a string.
 * @param input The shell command to run, either as a file path or as a string.
 * @return The output of the shell command as a string.
 */
string Interop::runShell(bool isFile, string input){
    string command = "";
    string outputFile = "temp_output.txt";

    if (isFile) {
        command = input + " > " + outputFile;
    } else {
        command = "echo \"" + input + "\" > " + outputFile;
    }

    // Execute the command
    int result = system(command.c_str());
    if (result != 0) {
        return "Error: Command execution failed.";
    }

    // Read the output from the temporary file
    ifstream outputFileStream(outputFile);
    if (!outputFileStream.is_open()) {
        return "Error: Unable to read output.";
    }

    string output((istreambuf_iterator<char>(outputFileStream)), istreambuf_iterator<char>());
    outputFileStream.close();

    // Clean up temporary files
    remove(outputFile.c_str());

    return output;
}