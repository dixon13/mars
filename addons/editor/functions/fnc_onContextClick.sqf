/*
 * Author: Kingsley
 * Handles clicking a context menu item
 *
 * Arguments:
 * 0: Action <STRING>
 * 1: Requires position? <BOOL>
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

params [["_action", ""], ["_requiresPosition", false]];

[] call FUNC(closeContextMenu);

if (_requiresPosition) then {
    GVAR(hasLeftClicked) = false;
    GVAR(isWaitingForLeftClick) = true;
    
    GVAR(contextPosLinePFH) = [{
        params ["_args","_handle"];
        _args params ["_selection","_action"];
        
        if (GVAR(hasLeftClicked)) exitWith {
            _worldPos = AGLtoASL (screenToWorld GVAR(mousePos));
            [_selection, _worldPos] call compile _action;
            
            [_handle] call CBA_fnc_removePerFrameHandler;
            
            GVAR(hasLeftClicked) = false;
            GVAR(isWaitingForLeftClick) = false;
        };
        
        _groups = [_selection] call EFUNC(common,unitsToGroups);
        _worldPos = AGLtoASL (screenToWorld GVAR(mousePos));
        _worldPos set [2, 1];
        
        {
            _objectPos = ASLtoAGL (getPosASLVisual (leader _x));
            _objectPos set [2, ((_objectPos select 2) + 5)];
            
            // Do drawLine3D 50 times to make it thicker (cheers BIS)
            for "_i" from 0 to 50 do {
                drawLine3D [_objectPos, _worldPos, [0,0,0,1]];
            };
            
            false
        } count _groups;
        
        drawIcon3D [
            "\A3\ui_f\data\map\groupicons\waypoint.paa",
            [0,0,0,1],
            _worldPos,
            1,
            1,
            0,
            "",
            2,
            0.03,
            "PuristaBold",
            "center"
        ];
    }, 0, [GVAR(selection), _action]] call CBA_fnc_addPerFrameHandler;
} else {
    [GVAR(selection)] call compile _action;
};