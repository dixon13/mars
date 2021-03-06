#include "script_component.hpp"

[QMODNAME, "OpenMissionEditor", ["Open Mission Editor", "Press to open the mission editor interface"], {
    if (GVAR(isRemoteControl)) then {
        [false] call FUNC(exitRemoteControl);
    };
    
    [] spawn FUNC(openEditor);
}, ""] call CBA_fnc_addKeybind;

// Object creation handler
[QGVAR(spawnObject), {
    _this call FUNC(spawnObject);
    
    #ifdef DEBUG_MODE_FULL
        MARS_LOGINFO("Spawned object(s)");
    #endif
}] call CBA_fnc_addEventHandler;

// Is this needed?
createCenter west;
createCenter east;
createCenter resistance;
createCenter civilian;
