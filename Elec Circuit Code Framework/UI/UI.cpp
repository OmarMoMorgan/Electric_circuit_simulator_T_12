#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}
void UI::ClearWindow()const
{
	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, height);
}
void UI::DO(bool x) {
	if (x) {
		AppMode = DESIGN;	//Design Mode is the mode now

		ClearStatusBar();     // Clear any Text in the Status Bar
		ClearWindow();         /// For drawing all the background in White


		ChangeTitle("Logic Simulator Project");

		CreateDesignToolBar();	//Create the desgin toolbar
		CreateStatusBar();		//Create Status bar
	}
	else {
		AppMode = SIMULATION;	//Simulation Mode is the mode now


		ClearStatusBar();                  // Clear any Text in the Status Bar
		ClearWindow();                  /// For drawing all the background in White

		ChangeTitle("The Simulation Mode");
		CreateSimulationToolBar();	//Create the Simulation toolbar
		CreateStatusBar();		//Create Status bar
	}
}

int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_GRD:   return ADD_GROUND;
			case ITM_BAT:   return ADD_BATTERY;
			case ITM_SWI:   return ADD_SWITCH;
			case ITM_BULB:  return ADD_BULB;
			case ITM_CABLE: return ADD_CONNECTION;
			case ITM_COPY: return COPY;
			case ITM_SIM: return SIM_MODE;
			case ITM_LAB: return ADD_Label;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE:	return SAVE;

			case ITM_EXIT:	return EXIT;


			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_CIRC_SIM:	return DSN_MODE;
				//case ITM_Switch_ON_OFF: return ADD_SWITCH;

			case ITM_EXIT_1:	return EXIT;


			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area

void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
void UI::drawtext(int mx, int my, string mm) const
{
	pWind->SetPen(RED, 5);
	return pWind->DrawString(mx, my, mm);
}
void UI::ClearLabel(int x, int y) const
{
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(x, y, 400, 100);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_GRD] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_BAT] = "images\\Menu\\Menu_battery.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_SWI] = "images\\Menu\\Menu_Resistor.jpg";	//should be changed to actual switch image
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_CABLE] = "images\\Menu\\Menu_Cable.jpg";
	MenuItemImages[ITM_SIM] = "images\\Menu\\Menu_Switch_To_Simulation.jpeg";     // Icon of Switch to Simulation Mode
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_Copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Menu_Paste1.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_Cut.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_Delete.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_Redo.jpg";

	MenuItemImages[ITM_LAB] = "images\\Menu\\Menu_Label.jpeg";

	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_Exit.jpg";

	
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode


	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_CIRC_SIM] = "images\\Menu\\Menu_Switch_To_Design.jpeg";
	MenuItemImages[ITM_Switch_ON_OFF] = "images\\Menu\\Menu_Switch.jpg";

	MenuItemImages[ITM_EXIT_1] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Bulb_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Bulb.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

//TODO: Add similar functions to draw all other components

void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted Battery //other image should be used
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal battery /other image should be used

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted Switch //should be changed to actual switch image
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal Switch //should be changed to actual switch image

	//Draw Switch at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Ground_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Ground.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	if (selected) {
		pWind->SetPen(RED, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else {
		pWind->SetPen(BLUE, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}

	//TODO: Add code to draw connection
}

void UI::DrawWhite_component(const int* r_GfxInfo) const 
{
	string ResImage;
	ResImage = "Images\\Comp\\Whiting.jpg";
	//pWind->SetPen(RED, 5);
	pWind->SetBrush(RED);
	//pWind->DrawImage(ResImage, r_GfxInfo[0], r_GfxInfo[1], COMP_WIDTH, COMP_HEIGHT);
	
	pWind->DrawRectangle(r_GfxInfo[0] - COMP_WIDTH/2, r_GfxInfo[1] - COMP_HEIGHT/2, r_GfxInfo[2] + COMP_WIDTH/2, r_GfxInfo[3] +COMP_HEIGHT/2);
}


UI::~UI()
{
	delete pWind;
}