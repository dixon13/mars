/*
 * Author: Kingsley
 * Highlights the given object and adds it to the selection array
 *
 * Arguments:
 * 0: Object <OBJECT>
 * 1: Is vehicle <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * N/A
 *
 * Public: No
 */

#include "script_component.hpp"

params [
    "_object",
    "_isVehicle",
    ["_emptySelection", true]
];

if (_object == GVAR(prepSurfaceSphere)) exitWith {};

if (_object in GVAR(selection) && !GVAR(ctrlKey)) exitWith {};

/*if (GVAR(ctrlKey) && count GVAR(selection) == 0) exitWith {
    GVAR(selection) = (units (group _object)) apply {vehicle _x};
};*/

if (GVAR(ctrlKey)) then {
    if (_object in GVAR(selection)) then {
        GVAR(selection) deleteAt (GVAR(selection) find _object);
    };
};

if (!GVAR(ctrlKey)) then {
    if (_emptySelection) then {
        GVAR(selection) = [];
    };
};

GVAR(selection) pushBackUnique _object;
