#include <bits/stdc++.h>
using namespace std;

class Command
{

private:
    string commandName;

public:
    string getCommandName()
    {
        return commandName;
    }

    /**
     * Constructor. It takes the input line and parses the command name and param out of it. If the
     * command or its given params are not valid, then {@link InvalidCommandException} is thrown.
     *
     * @param inputLine Given input command line.
     */
    Command(string inputLine)
    {
        commandName = inputLine;
    }
}