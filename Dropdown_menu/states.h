#ifndef STATES_H
#define STATES_H

#include <map>

enum ObjectState{
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    //TEXTBOX_UPDATE,

    OPEN,
    CLOSE,
    NEW,
    SAVE,
    UNDO,
    REDO,
    EXPORT,

    OPEN_FILE,

    ///This should always be the last state
    LASTSTATE
};

class States
{
public:
    States();
    static bool is_State_Enable(ObjectState state);
    static void enable_state(ObjectState state);
    static void disable_state(ObjectState state);
    static void set_current_file(std::string file_name);
    static std::string get_current_file();

    std::map<ObjectState, bool> get_states() const;
    void set_states(std::map<ObjectState, bool> states);

private:
    static std::map<ObjectState, bool> states;
    static std::string current_file_name;
};

#endif // STATES_H
