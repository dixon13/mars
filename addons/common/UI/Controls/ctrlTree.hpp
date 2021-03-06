class MARS_gui_ctrlTree: MARS_gui_ctrlDefaultText {
    type = CT_TREE;
    colorBorder[] = {0,0,0,1};
    colorLines[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0};
    colorPictureRightDisabled[] = {0,0,0,0};
    colorPictureRightSelected[] = {0,0,0,0};
    colorPictureSelected[] = {0,0,0,0};
    colorPictureDisabled[] = {0,0,0,0};
    colorSelect[] = {COLOR_ACTIVE_RGBA};
    colorMarked[] = {COLOR_ACTIVE_RGB,0.5};
    colorMarkedSelected[] = {COLOR_ACTIVE_RGBA};
    colorText[] = {COLOR_TEXT_RGBA};
    colorSelectText[] = {1,1,1,1};
    colorMarkedText[] = {1,1,1,1};
    colorPicture[] = {1,1,1,1};
    colorPictureRight[] = {1,0,1,1};
    multiselectEnabled = 0;
    expandOnDoubleclick = 1;
    hiddenTexture = "\a3\3DEN\Data\Controls\ctrlTree\hiddenTexture_ca.paa";
    expandedTexture = "\a3\3DEN\Data\Controls\ctrlTree\expandedTexture_ca.paa";
    maxHistoryDelay = 1;
    disableKeyboardSearch = 0;
    colorDisabled[] = {0,0,0,0};
    colorArrow[] = {0,0,0,0};
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

    class ScrollBar: ScrollBar {
        scrollSpeed = 0.05;
    };
};