/*
 * Author: Kingsley
 * Gets the objects' type based on the given config
 *
 * Arguments:
 * 0: Object config string <STRING>
 *
 * Return Value:
 * Object type (man, vehicle, group) <STRING>
 *
 * Example:
 * TODO
 *
 * Public: Yes
 */

#include "script_component.hpp"

params [["_config", "", [""]]];

private _cfg = call compile _config;

["vehicle", "man"] select (getNumber (_cfg >> "isMan"));
