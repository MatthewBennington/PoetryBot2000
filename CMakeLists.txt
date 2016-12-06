cmake_minimum_required(VERSION 3.6)
project(Final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ArgumentParsing/ArgParser.cpp ArgumentParsing/ArgParser.h ArgumentParsing/Options.cpp ArgumentParsing/Options.h Word.cpp Word.h TextParsing/RawTextParser.cpp TextParsing/RawTextParser.h TextParsing/Parser.h PrettyPrinter.cpp PrettyPrinter.h WordVector.cpp WordVector.h FilePrinter.cpp FilePrinter.h TextParsing/ParsedTextParser.cpp TextParsing/ParsedTextParser.h)
add_executable(Final ${SOURCE_FILES})