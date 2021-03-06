#ifndef MARS_DEFINE_H
#define MARS_DEFINE_H

#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_CHECKBOX 77
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW 10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_SHORTCUTBUTTON 16
#define CT_XKEYDESC 40
#define CT_XBUTTON 41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_ANIMATED_USER 99
#define CT_MAP 100
#define CT_MAP_MAIN 101
#define CT_LISTNBOX 102

#define ST_POS 0x0F
#define ST_HPOS 0x03
#define ST_VPOS 0x0C
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0c

#define ST_TYPE 0xF0
#define ST_SINGLE 0
#define ST_MULTI 16
#define ST_TITLE_BAR 32
#define ST_PICTURE 48
#define ST_FRAME 64
#define ST_BACKGROUND 80
#define ST_GROUP_BOX 96
#define ST_GROUP_BOX2 112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE 144
#define ST_WITH_RECT 160
#define ST_LINE 176
#define ST_UPPERCASE 0xC0
#define ST_LOWERCASE 0xD0

#define ST_SHADOW 0x100
#define ST_NO_RECT 0x200
#define ST_KEEP_ASPECT_RATIO 0x800

#define ST_TITLE ST_TITLE_BAR + ST_CENTER

#define SL_DIR 0x400
#define SL_VERT 0
#define SL_HORZ 0x400

#define SL_TEXTURES 0x10

#define LB_TEXTURES 0x10
#define LB_MULTI 0x20
#define FONT_MARS "RobotoCondensed"
#define BG_OPACITY 0.8

class RscFrame {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
};

class RscText;
class RscEdit;
class RscTitle;
class RscListbox;
class RscControlsGroupNoScrollbars;
class RscPicture;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscStandardDisplay;
class RscVignette;
class RscMap;
class RscCombo;

#include "macros.hpp"

#include "UI\Controls\ctrlDefault.hpp"
#include "UI\Controls\ctrlStatic.hpp"
#include "UI\Controls\ctrlButton.hpp"
#include "UI\Controls\ctrlEdit.hpp"
#include "UI\Controls\ctrlSlider.hpp"
#include "UI\Controls\ctrlCombo.hpp"
#include "UI\Controls\ctrlListbox.hpp"
#include "UI\Controls\ctrlToolbox.hpp"
#include "UI\Controls\ctrlCheckboxes.hpp"
#include "UI\Controls\ctrlProgress.hpp"
#include "UI\Controls\ctrlHTML.hpp"
#include "UI\Controls\ctrlActiveText.hpp"
#include "UI\Controls\ctrlTree.hpp"
#include "UI\Controls\ctrlStructuredText.hpp"
#include "UI\Controls\ctrlControlsGroup.hpp"
#include "UI\Controls\ctrlShortcutButton.hpp"
#include "UI\Controls\ctrlXListbox.hpp"
#include "UI\Controls\ctrlXSlider.hpp"
#include "UI\Controls\ctrlMenu.hpp"
#include "UI\Controls\ctrlMenuStrip.hpp"
#include "UI\Controls\ctrlObject.hpp"
#include "UI\Controls\ctrlObjectContainer.hpp"
#include "UI\Controls\ctrlObjectZoom.hpp"
#include "UI\Controls\ctrlMap.hpp"
#include "UI\Controls\ctrlMapMain.hpp"
#include "UI\Controls\ctrlListNBox.hpp"
#include "UI\Controls\ctrlCheckbox.hpp"

class MARS_gui_treeBase {
    access = 0;
    idc = -1;
    type = CT_TREE;
    style = ST_LEFT;
    default = 0;
    blinkingPeriod = 0;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    colorBorder[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0}; // Fill color
    colorSelect[] = {COLOR_ACTIVE_RGB,0.5}; // Selected item fill color (when multiselectEnabled is 0)
    colorMarked[] = {COLOR_ACTIVE_RGB,0.25}; // Marked item fill color (when multiselectEnabled is 1)
    colorMarkedSelected[] = {COLOR_ACTIVE_RGB,0.5}; // Selected item fill color (when multiselectEnabled is 1)
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    font = "RobotoCondensedLight";
    shadow = 0;
    colorText[] = {1,1,1,1}; // Text color
    colorSelectText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 0)
    colorMarkedText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 1)
    tooltip = ""; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {0,0,0,0}; // Tooltip frame color
    multiselectEnabled = 1; // Allow selecting multiple items while holding Ctrl or Shift
    expandOnDoubleclick = 1; // Expand/collapse item upon double-click
    hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa"; // Expand icon
    expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa"; // Collapse icon
    maxHistoryDelay = 10e10; // Time since last keyboard type search to reset it

    // Scrollbar configuration
    class ScrollBar
    {
        width = 0.1; // width of ScrollBar
        height = 1; // height of ScrollBar
        scrollSpeed = 0.01; // scroll speed of ScrollBar
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)
        color[] = {1,1,1,1}; // Scrollbar color
    };

    colorDisabled[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
    colorArrow[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
    onCanDestroy = "";
    onDestroy = "";
    onMouseEnter = "";
    onMouseExit = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";
    onTreeSelChanged = "";
    onTreeLButtonDown = "";
    onTreeDblClick = "";
    onTreeExpanded = "";
    onTreeCollapsed = "";
    onTreeMouseExit = "";
};

class MARS_gui_treeABBase: MARS_gui_treeBase {
    multiselectEnabled = 0;
    class ScrollBar {
        width = 0.125;
        height = 1;
        scrollSpeed = 0.25;
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        color[] = {1,1,1,1};
    };
};

class MARS_gui_textBase {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 0;
    idc = -1;
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {1, 1, 1, 1};
    text = "";
    fixedWidth = 0;
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    style = 0;
    shadow = 1;
    colorShadow[] = {0, 0, 0, 0.5};
    font = FONT_MARS;
    sizeEx = 0.032;
    linespacing = 1;
    tooltipColorText[] = {1, 1, 1, 1};
    tooltipColorBox[] = {1, 1, 1, 1};
    tooltipColorShade[] = {0, 0, 0, 0.65};
};

class MARS_gui_sliderBase {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 3;
    style = 1024;
    w = 0.3;
    color[] = {1, 1, 1, 0.8};
    colorActive[] = {1, 1, 1, 1};
    shadow = 0;
    h = 0.025;
};

class MARS_gui_backgroundBase {
    type = 0;
    idc = -1;
    style = 128;
    colorBackground[] = {0,0,0,BG_OPACITY};
    colorText[] = {1,1,1,1};
    font = FONT_MARS;
    text = "";
    sizeEx = 0.032;
};

class MARS_gui_backgroundBaseSolid : MARS_gui_backgroundBase {
    colorBackground[] = {0.088,0.088,0.088,1};
};

class MARS_gui_accentBase : MARS_gui_backgroundBase {
    colorBackground[] = {COLOR_ACTIVE_RGBA};
};

class MARS_gui_editBase {
    access = 0;
    type = 2;
    x = 0;
    y = 0;
    h = 0.04;
    w = 0.2;
    colorBackground[] = {
        0,
        0,
        0,
        1
    };
    colorText[] = {
        0.95,
        0.95,
        0.95,
        1
    };
    colorSelection[] = {
        "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])",
        "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])",
        "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])",
        1
    };
    autocomplete = "";
    text = "";
    size = 0.2;
    style = "0x00 + 0x40";
    font = "RobotoCondensed";
    shadow = 2;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorDisabled[] = {
        1,
        1,
        1,
        0.25
    };
};

class MARS_gui_buttonBase {
    idc = -1;
    type = 16;
    style = ST_VCENTER;
    text = "";
    action = "";
    x = 0.0;
    y = 0.0;
    w = 0.25;
    h = 0.04;
    size = 0.03921;
    sizeEx = 0.032;
    colorBackground[] = {0, 0, 0, BG_OPACITY};
    colorBackgroundFocused[] = {1, 1, 1, 1};
    colorBackground2[] = {0.75, 0.75, 0.75, 1};
    color[] = {1, 1, 1, 1};
    colorFocused[] = {0, 0, 0, 1};
    color2[] = {0, 0, 0, 1};
    colorText[] = {1, 1, 1, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    period = 1.2;
    periodFocus = 1.2;
    periodOver = 1.2;
    default = 0;
    textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
    font = FONT_MARS;
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.0, 0};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};

    class HitZone {
        left = 0.00;
        top = 0.00;
        right = 0.00;
        bottom = 0.00;
    };

    class ShortcutPos {
        left = 0.00;
        top = 0.00;
        w = 0.00;
        h = 0.00;
    };

    class TextPos {
        left = 0.002;
        top = 0.0004;
        right = 0.0;
        bottom = 0.00;
    };

    class Attributes {
        font = FONT_MARS;
        color = "#E5E5E5";
        align = "center";
        shadow = "1";
    };
    class AttributesImage {
        font = FONT_MARS;
        color = "#E5E5E5";
        align = "left";
        shadow = "1";
    };
};

class MARS_gui_buttonBaseSolid: MARS_gui_buttonBase {
    colorBackground[] = {0.088,0.088,0.088,1};
    sizeEx = 0.03;
};

class MARS_gui_sliderXBase {
    access = 0;
    idc = CT_XSLIDER;
    type = CT_XSLIDER;
    style = SL_HORZ;
    default = 0;
    blinkingPeriod = 0;
    x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
    w = 10 * GUI_GRID_CENTER_W;
    h = 1 * GUI_GRID_CENTER_H;
    color[] = {1, 1, 1, 1};
    colorDisabled[] = {1, 1, 1, 0.5};
    colorActive[] = {1, 1, 1, 1};
    tooltip = "";
    tooltipColorShade[] = {0, 0, 0, 1};
    tooltipColorText[] = {1, 1, 1, 1};
    tooltipColorBox[] = {0, 0, 0, 1};
    arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
    arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
    border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
    thumb = "#(argb,8,8,3)color(1,1,1,1)";
};

class MARS_gui_spacerBaseSolid: MARS_gui_buttonBase {
    type = 0;
    idc = -1;
    style = 128;
    text = "";
    colorText[] = {0.088,0.088,0.088,1};
    colorBackground[] = {0.088,0.088,0.088,1};
    font = FONT_MARS;
    sizeEx = 0;
    shadow = 0;
    x = 0.1;
    y = 0.1;
    w = 0.1;
    h = 0.1;
};

class MARS_gui_spacerBase: MARS_gui_buttonBase {
    type = 0;
    idc = -1;
    style = 128;
    text = "";
    colorText[] = {0.088,0.088,0.088,BG_OPACITY};
    colorBackground[] = {0.088,0.088,0.088,BG_OPACITY};
    font = FONT_MARS;
    sizeEx = 0;
    shadow = 0;
    x = 0.1;
    y = 0.1;
    w = 0.1;
    h = 0.1;
};

class MARS_gui_tabBase {
    access = 0;
    idc = -1;
    type = CT_BUTTON;
    style = ST_PICTURE + ST_CENTER + ST_VCENTER + ST_KEEP_ASPECT_RATIO;
    text = "";
    action = "";
    x = 0.0;
    y = 0.0;
    w = 0.25;
    h = 0.04;
    offsetPressedX = 0;
	offsetPressedY = 0;
	offsetX = 0;
	offsetY = 0;
	shadow = 0;
    sizeEx = 0.032;
    borderSize = 0;
    colorBorder[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0};
    colorBackgroundActive[] = {0,0,0,0};
    colorBackgroundDisabled[] = {0,0,0,0};
    colorDisabled[] = {1,1,1,0.5};
    colorFocused[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    color[] = {1,1,1,1};
    blinkingPeriod = 0;
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {0,0,0,0};
    font = FONT_MARS;
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.0, 0};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
};

class MARS_gui_menuBase {
    access = 0;
    idc = -1;
    type = 1;
    style = 0x02 + 160;
    text = "";
    action = "";
    x = 0.0;
    y = 0.0;
    w = 0.25;
    h = (0.03 * safeZoneH);
    offsetPressedX = 0;
	offsetPressedY = 0;
	offsetX = 0;
	offsetY = 0;
	shadow = 0;
    sizeEx = 0.032;
    borderSize = 0;
    colorBorder[] = {0,0,0,0};
    colorBackgroundActive[] = {COLOR_ACTIVE_RGBA};
    colorBackgroundDisabled[] = {1,1,1,0.25};
    colorDisabled[] = {1,1,1,0.5};
    colorFocused[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    color[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    blinkingPeriod = 0;
    tooltipColorShade[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {0,0,0,1};
    font = FONT_NORMAL;
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.0, 0};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
};

class MARS_gui_menuTopBase: MARS_gui_menuBase {
    sizeEx = 0.032;
    font = FONT_NORMAL;
};

class MARS_gui_contextBase {
    access = 0;
    idc = -1;
    type = 1;
    style = 0x00 + 0x0c + 160;
    text = "";
    action = "";
    x = 0.0;
    y = 0.0;
    w = 0.25;
    h = 0.04;
    offsetPressedX = 0;
	offsetPressedY = 0;
	offsetX = 0;
	offsetY = 0;
	shadow = 0;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    borderSize = 0;
    colorBorder[] = {0.1,0.1,0.1,0.8};
    colorBackgroundActive[] = {COLOR_ACTIVE_RGBA};
    colorBackgroundDisabled[] = {1,1,1,0.25};
    colorDisabled[] = {1,1,1,0.5};
    colorFocused[] = {0.1,0.1,0.1,0.8};
    colorShadow[] = {0.1,0.1,0.1,0.8};
    colorText[] = {1,1,1,1};
    color[] = {1,1,1,1};
    colorBackground[] = {0.1,0.1,0.1,0.8};
    blinkingPeriod = 0;
    tooltipColorShade[] = {0.1,0.1,0.1,0.8};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {0.1,0.1,0.1,0.8};
    font = "RobotoCondensedLight";
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.0, 0};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
};

class MARS_gui_toolbarContextBase: MARS_gui_contextBase {
    sizeEx = 0.032;
    colorBorder[] = {0,0,0,0};
    colorBackgroundActive[] = {COLOR_ACTIVE_RGBA};
    colorBackgroundDisabled[] = {COLOR_TAB_RGB,0.25};
    colorDisabled[] = {1,1,1,0.5};
    colorFocused[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    color[] = {1,1,1,1};
    colorBackground[] = {COLOR_TAB_RGBA};
};

class MARS_gui_RscProgress {
    type = 8;
    style = 0;
    colorFrame[] = {1, 1, 1, 0.7};
    colorBar[] = {1, 1, 1, 0.7};
    texture = "#(argb,8,8,3)color(1,1,1,0.7)";
    x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)";
    y = "10 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
    w = "38 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "0.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
};

class MARS_gui_staticBase {
    idc = -1;
    type = CT_STATIC;
    x = 0.0;
    y = 0.0;
    w = 0.183825;
    h = 0.104575;
    style = ST_LEFT;
    font = FONT_MARS;
    sizeEx = 0.032;
    colorText[] = {0.95, 0.95, 0.95, 1.0};
    colorBackground[] = {0, 0, 0, 0};
    text = "";
};

class MARS_gui_listBoxBase : RscListBox {
    type = CT_LISTBOX;
    style = ST_MULTI;
    font = FONT_MARS;
    sizeEx = 0.03921;
    color[] = {1, 1, 1, 1};
    colorText[] = {0.543, 0.5742, 0.4102, 1.0};
    colorScrollbar[] = {0.95, 0.95, 0.95, 1};
    colorSelect[] = {0.95, 0.95, 0.95, 1};
    colorSelect2[] = {0.95, 0.95, 0.95, 1};
    colorSelectBackground[] = {0, 0, 0, 1};
    colorSelectBackground2[] = {0.543, 0.5742, 0.4102, 1.0};
    colorDisabled[] = {"(profileNamespace getVariable ['GUI_BCG_RGB_R',0.69])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.75])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.5])", 0.25};
    period = 1.2;
    rowHeight = 0.03;
    colorBackground[] = {0, 0, 0, 1};
    maxHistoryDelay = 1.0;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    soundSelect[] = {"", 0.1, 1};
    soundExpand[] = {"", 0.1, 1};
    soundCollapse[] = {"", 0.1, 1};
    class ListScrollBar {
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        autoScrollDelay = 5;
        autoScrollEnabled = 0;
        autoScrollRewind = 0;
        autoScrollSpeed = -1;
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        height = 0;
        scrollSpeed = 0.06;
        shadow = 0;
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        width = 0;
    };
    class ScrollBar {
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        thumb = "";
        arrowFull = "";
        arrowEmpty = "";
        border = "";
    };
};


class MARS_gui_listNBox {
    access = 0;
    type = CT_LISTNBOX;// 102;
    style = ST_MULTI;
    w = 0.4;
    h = 0.4;
    font = FONT_MARS;
    sizeEx = 0.031;

    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
    arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
    columns[] = {0.0};
    color[] = {1, 1, 1, 1};

    rowHeight = 0.03;
    colorBackground[] = {0, 0, 0, 0.2};
    colorText[] = {1, 1, 1, 1.0};
    colorScrollbar[] = {0.95, 0.95, 0.95, 1};
    colorSelect[] = {0.95, 0.95, 0.95, 1};
    colorSelect2[] = {0.95, 0.95, 0.95, 1};
    colorSelectBackground[] = {0, 0, 0, 0.0};
    colorSelectBackground2[] = {0.0, 0.0, 0.0, 0.5};
    colorActive[] = {0, 0, 0, 1};
    colorDisabled[] = {0, 0, 0, 0.3};
    rows = 1;

    drawSideArrows = 0;
    idcLeft = -1;
    idcRight = -1;
    maxHistoryDelay = 1;
    soundSelect[] = {"", 0.1, 1};
    period = 1;
    shadow = 2;
    class ScrollBar {
        arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
        arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
        border = "#(argb,8,8,3)color(1,1,1,1)";
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        thumb = "#(argb,8,8,3)color(1,1,1,1)";
    };
    class ListScrollBar {
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        autoScrollDelay = 5;
        autoScrollEnabled = 0;
        autoScrollRewind = 0;
        autoScrollSpeed = -1;
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        height = 0;
        scrollSpeed = 0.06;
        shadow = 0;
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        width = 0;
    };
};

class MARS_gui_comboBoxBase : RscCombo {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 4;
    colorSelect[] = {0, 0, 0, 1};
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 1};
    colorScrollbar[] = {1, 0, 0, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    colorPicture[] = {1, 1, 1, 1};
    colorPictureSelected[] = {1, 1, 1, 1};
    colorPictureDisabled[] = {1, 1, 1, 0.25};
    colorPictureRight[] = {1, 1, 1, 1};
    colorPictureRightSelected[] = {1, 1, 1, 1};
    colorPictureRightDisabled[] = {1, 1, 1, 0.25};
    colorTextRight[] = {1, 1, 1, 1};
    colorSelectRight[] = {0, 0, 0, 1};
    colorSelect2Right[] = {0, 0, 0, 1};
    tooltipColorText[] = {1, 1, 1, 1};
    tooltipColorBox[] = {1, 1, 1, 1};
    tooltipColorShade[] = {0, 0, 0, 0.65};
    soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect", 0.1, 1};
    soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand", 0.1, 1};
    soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse", 0.1, 1};
    maxHistoryDelay = 1;
    class ComboScrollBar {
        color[] = {1, 1, 1, 1};
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)
    };
    style = "0x10 + 0x200";
    font = FONT_MARS;
    sizeEx = 0.032;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.12;
    h = 0.035;
    colorSelectBackground[] = {1, 1, 1, 0.7};
    arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
    arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
    wholeHeight = 0.45;
    colorActive[] = {1, 0, 0, 1};
};

class MARS_gui_mapBase {
    moveOnEdges = 1;
    x = "SafeZoneXAbs";
    y = "SafeZoneY + 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    w = "SafeZoneWAbs";
    h = "SafeZoneH - 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    type = 100; // Use 100 to hide markers
    style = 48;
    shadow = 0;

    ptsPerSquareSea = 5;
    ptsPerSquareTxt = 3;
    ptsPerSquareCLn = 10;
    ptsPerSquareExp = 10;
    ptsPerSquareCost = 10;
    ptsPerSquareFor = 9;
    ptsPerSquareForEdge = 9;
    ptsPerSquareRoad = 6;
    ptsPerSquareObj = 9;
    showCountourInterval = 0;
    scaleMin = 0.001;
    scaleMax = 1.0;
    scaleDefault = 0.16;
    maxSatelliteAlpha = 0.85;
    alphaFadeStartScale = 0.35;
    alphaFadeEndScale = 0.4;
    colorBackground[] = {0.969, 0.957, 0.949, 1.0};
    colorSea[] = {0.467, 0.631, 0.851, 0.5};
    colorForest[] = {0.624, 0.78, 0.388, 0.5};
    colorForestBorder[] = {0.0, 0.0, 0.0, 0.0};
    colorRocks[] = {0.0, 0.0, 0.0, 0.3};
    colorRocksBorder[] = {0.0, 0.0, 0.0, 0.0};
    colorLevels[] = {0.286, 0.177, 0.094, 0.5};
    colorMainCountlines[] = {0.572, 0.354, 0.188, 0.5};
    colorCountlines[] = {0.572, 0.354, 0.188, 0.25};
    colorMainCountlinesWater[] = {0.491, 0.577, 0.702, 0.6};
    colorCountlinesWater[] = {0.491, 0.577, 0.702, 0.3};
    colorPowerLines[] = {0.1, 0.1, 0.1, 1.0};
    colorRailWay[] = {0.8, 0.2, 0.0, 1.0};
    colorNames[] = {0.1, 0.1, 0.1, 0.9};
    colorInactive[] = {1.0, 1.0, 1.0, 0.5};
    colorOutside[] = {0.0, 0.0, 0.0, 1.0};
    colorTracks[] = {0.84, 0.76, 0.65, 0.15};
    colorTracksFill[] = {0.84, 0.76, 0.65, 1.0};
    colorRoads[] = {0.7, 0.7, 0.7, 1.0};
    colorRoadsFill[] = {1.0, 1.0, 1.0, 1.0};
    colorMainRoads[] = {0.9, 0.5, 0.3, 1.0};
    colorMainRoadsFill[] = {1.0, 0.6, 0.4, 1.0};
    colorGrid[] = {0.1, 0.1, 0.1, 0.6};
    colorGridMap[] = {0.1, 0.1, 0.1, 0.6};
    colorText[] = {1, 1, 1, 0.85};
    font = "RobotoCondensed";
    sizeEx = 0.0270000;
    stickX[] = {0.20, {"Gamma", 1.00, 1.50}};
    stickY[] = {0.20, {"Gamma", 1.00, 1.50}};
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";

    fontLabel = "RobotoCondensed";
    sizeExLabel = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontGrid = "TahomaB";
    sizeExGrid = 0.02;
    fontUnits = "TahomaB";
    sizeExUnits = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontNames = "RobotoCondensed";
    sizeExNames = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8) * 2";
    fontInfo = "RobotoCondensed";
    sizeExInfo = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontLevel = "TahomaB";
    sizeExLevel = 0.02;
    text = "#(argb,8,8,3)color(1,1,1,1)";
    class ActiveMarker {
        color[] = {0.30, 0.10, 0.90, 1.00};
        size = 50;
    };
    class Legend {
        x = "SafeZoneX + (((safezoneW / safezoneH) min 1.2) / 40)";
        y = "SafeZoneY + safezoneH - 4.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        w = "10 * (((safezoneW / safezoneH) min 1.2) / 40)";
        h = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        font = "RobotoCondensed";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
        colorBackground[] = {1, 1, 1, 0.5};
        color[] = {0, 0, 0, 1};
    };
    class Task {
        icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
        iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
        iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
        iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
        iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
        color[] = {"(profileNamespace getVariable ['IGUI_TEXT_RGB_R',0])", "(profileNamespace getVariable ['IGUI_TEXT_RGB_G',1])", "(profileNamespace getVariable ['IGUI_TEXT_RGB_B',1])", "(profileNamespace getVariable ['IGUI_TEXT_RGB_A',0.8])"};
        colorCreated[] = {1, 1, 1, 1};
        colorCanceled[] = {0.7, 0.7, 0.7, 1};
        colorDone[] = {0.7, 1, 0.3, 1};
        colorFailed[] = {1, 0.3, 0.2, 1};
        size = 27;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };
    class Waypoint {
        icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        color[] = {0, 0, 0, 1};
        size = 20;
        importance = "1.2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };
    class WaypointCompleted {
        icon = "\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
        color[] = {0, 0, 0, 1};
        size = 20;
        importance = "1.2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };
    class CustomMark {
        icon = "\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
        size = 24;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
        color[] = {0, 0, 0, 1};
    };
    class Command {
        icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        size = 18;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
        color[] = {1, 1, 1, 1};
    };
    class Bush {
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        color[] = {0.45, 0.64, 0.33, 0.4};
        size = "14/2";
        importance = "0.2 * 14 * 0.05 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Rock {
        icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
        color[] = {0.1, 0.1, 0.1, 0.8};
        size = 12;
        importance = "0.5 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class SmallTree {
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        color[] = {0.45, 0.64, 0.33, 0.4};
        size = 12;
        importance = "0.6 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Tree {
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        color[] = {0.45, 0.64, 0.33, 0.4};
        size = 12;
        importance = "0.9 * 16 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class busstop {
        icon = "\A3\ui_f\data\map\mapcontrol\busstop_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class fuelstation {
        icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class hospital {
        icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class church {
        icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class lighthouse {
        icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class power {
        icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class powersolar {
        icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class powerwave {
        icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class powerwind {
        icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class quay {
        icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class shipwreck {
        icon = "\A3\ui_f\data\map\mapcontrol\shipwreck_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class transmitter {
        icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class watertower {
        icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {1, 1, 1, 1};
    };
    class Cross {
        icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {0, 0, 0, 1};
    };
    class Chapel {
        icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1.0;
        color[] = {0, 0, 0, 1};
    };
    class Bunker {
        icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        size = 14;
        importance = "1.5 * 14 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class Fortress {
        icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        size = 16;
        importance = "2 * 16 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class Fountain {
        icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
        size = 11;
        importance = "1 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class Ruin {
        icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
        size = 16;
        importance = "1.2 * 16 * 0.05";
        coefMin = 1;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class Stack {
        icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
        size = 20;
        importance = "2 * 16 * 0.05";
        coefMin = 0.9;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class Tourism {
        icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
        size = 16;
        importance = "1 * 16 * 0.05";
        coefMin = 0.7;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
    class ViewTower {
        icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
        size = 16;
        importance = "2.5 * 16 * 0.05";
        coefMin = 0.5;
        coefMax = 4;
        color[] = {0, 0, 0, 1};
    };
};

#endif