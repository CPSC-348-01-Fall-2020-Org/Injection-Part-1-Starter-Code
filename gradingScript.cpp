#include "exploit.h"
#include "gatherWithValidation.h"
#include <iostream>

using std::cout;
using std::endl;

namespace injectionAttacks
{
    void checkFoodStorage()
    {
        system("../check all");
    }

    bool testStudentCode()
    {
        causeErrorWithGatherCommand();
        causeErrorWithCheckCommand();
        viewContentsOfDataDirectory();
        viewContentsOfUserFile();
        insertNewUser("st_Pascal", "abc123xyz789");
        viewContentsOfUserFile();

        checkFoodStorage();

        gatherWithWhitelist("flour", "pantry");
        gatherWithWhitelist("driedFruits", "pantry");
        gatherWithWhitelist("sugar", "pantry");
        gatherWithWhitelist("oil", "pantry");
        gatherWithWhitelist("berries", "coldPantry");
        gatherWithWhitelist("tBoneSteaks", "iceBox");
        checkFoodStorage();

        gatherWithWhitelist("flour; ls #", "pantry");
        gatherWithWhitelist("flour; ls ./data #", "pantry");

        gatherWithWhitelist("flour | ls ./data #", "pantry");
        gatherWithWhitelist("flour & ls ./data #", "pantry");
        gatherWithWhitelist("flour && ls ./data #", "pantry");
        gatherWithWhitelist("flour \\`ls ./data #\\`", "pantry");
        gatherWithWhitelist("flour $(ls ./data) #", "pantry");
        gatherWithWhitelist("flour $(ls ./data | xargs) #", "pantry");
        gatherWithWhitelist("flour\nls ./data #", "pantry");
        gatherWithWhitelist("flour${IFS}ls${IFS%??}./data${IFS%??}#", "pantry");

        // blocked by the original file
        gatherWithWhitelist("flour; cat ./data/users.txt #", "pantry");
        gatherWithWhitelist("flour; cat ./data/*.txt #", "pantry");
        gatherWithWhitelist("flour; cat ./data/* #", "pantry");
        gatherWithWhitelist("flour; less ./data/* #", "pantry");
        gatherWithWhitelist("flour; more ./data/* #", "pantry");
        gatherWithWhitelist("flour; head ./data/* #", "pantry");
        gatherWithWhitelist("flour; tail ./data/* #", "pantry");
        gatherWithWhitelist("flour; nl ./data/* #", "pantry");
        gatherWithWhitelist("flour;\tcat\t./data/*\t#", "pantry");

        checkFoodStorage();

        gatherWithBlacklist("flour", "pantry");
        gatherWithBlacklist("driedFruits", "pantry");
        gatherWithBlacklist("sugar", "pantry");
        gatherWithBlacklist("oil", "pantry");
        gatherWithBlacklist("berries", "coldPantry");
        gatherWithBlacklist("tBoneSteaks", "iceBox");
        checkFoodStorage();

        gatherWithBlacklist("flour; ls #", "pantry");
        gatherWithBlacklist("flour; ls ./data #", "pantry");

        gatherWithBlacklist("flour | ls ./data #", "pantry");
        gatherWithBlacklist("flour & ls ./data #", "pantry");
        gatherWithBlacklist("flour && ls ./data #", "pantry");
        gatherWithBlacklist("flour \\`ls ./data #\\`", "pantry");
        gatherWithBlacklist("flour $(ls ./data) #", "pantry");
        gatherWithBlacklist("flour $(ls ./data | xargs) #", "pantry");
        gatherWithBlacklist("flour\nls ./data #", "pantry");
        gatherWithBlacklist("flour${IFS}ls${IFS%??}./data${IFS%??}#", "pantry");

        // blocked by the original file
        gatherWithBlacklist("flour; cat ./data/users.txt #", "pantry");
        gatherWithBlacklist("flour; cat ./data/*.txt #", "pantry");
        gatherWithBlacklist("flour; cat ./data/* #", "pantry");
        gatherWithBlacklist("flour; less ./data/* #", "pantry");
        gatherWithBlacklist("flour; more ./data/* #", "pantry");
        gatherWithBlacklist("flour; head ./data/* #", "pantry");
        gatherWithBlacklist("flour; tail ./data/* #", "pantry");
        gatherWithBlacklist("flour; nl ./data/* #", "pantry");
        gatherWithBlacklist("flour;\tcat\t./data/*\t#", "pantry");

        checkFoodStorage();

        // TODO
        // TODO
        // TODO
        // checkFoodStorage();

        // gatherWithWhitelist("legitimateInputForWhitelist", "pantry");
        // checkFoodStorage();
        // gatherWithBlacklist("legitimateInputForWhitelist", "pantry");
        // checkFoodStorage();

        // gatherWithWhitelist("malicious*&^command", "another_malicious!@#command");
        // checkFoodStorage();
        // gatherWithBlacklist("malicious*&^command", "another_malicious!@#command");
        // checkFoodStorage();

        return true;
    }
}

int main(int argc, char *argv[])
{
    return injectionAttacks::testStudentCode();
}
