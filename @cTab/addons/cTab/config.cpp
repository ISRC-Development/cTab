// cTab - Commander's Tablet with FBCB2 Blue Force Tracking
// Battlefield tablet to access real time intel and blue force tracker.
// By - Riouken
// http://forums.bistudio.com/member.php?64032-Riouken
// You may re-use any of this work as long as you provide credit back to me.


#define PREFIX cTab
#define COMPONENT main
#define MAJOR 2
#define MINOR 1
#define PATCHLVL 0
#define BUILD 1
#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD
#define REQUIRED_VERSION 1.0
#include "\x\cba\addons\main\script_macros_common.hpp"
#define AUTHOR "Riouken & Gundy"


class CfgPatches
{
	class PREFIX  // cTab
		{
			units[] = {Box_cTab_items};
			weapons[] = {ItemcTab,ItemAndroid,ItemMicroDAGR,ItemcTabHCam};
			requiredVersion = REQUIRED_VERSION;
			requiredAddons[] = {"CBA_MAIN"};
			versionDesc = "cTab";
			versionAct = "";
			VERSION_CONFIG;
			author[] = {"Riouken","Gundy"};
			authorUrl = "https://github.com/Riouken/cTab";
		};
};

class CfgSettings 
{
	class CBA 
	{
		class Versioning 
		{
			class PREFIX 
			{
				class Dependencies 
				{
					CBA[] = {"cba_main", { 1,0,0 },"true"};
				};
			};
		};
	};
};

class CfgMods {
	class PREFIX {
		dir = "@cTab";
		name = "cTab - Blue Force Tracking";
		picture = "\cTab\img\cTab_BFT_ico.paa";
		hidePicture = "True";
		hideName = "True";
		actionName = "Website";
		action = "https://github.com/Riouken/cTab";
		overview = "Commander's Tablet / FBCB2 - Blue Force Tracking\nBattlefield tablet to access real time intel and blue force tracker.";
		tooltip = "Commander's Tablet / FBCB2 - Blue Force Tracking";
		author = AUTHOR;
	};
};

#include "\userconfig\ctab\ctab_settings.hpp"

class Extended_PostInit_EventHandlers
{
	class PREFIX
	{
		clientInit = QUOTE(call COMPILE_FILE2(\cTab\player_init.sqf));

		serverInit = QUOTE(call COMPILE_FILE2(\cTab\server_init.sqf));
	};
};

#include <cTab_gui_macros.hpp>
#include <cTab_base_gui_classes.hpp>

#include <cTab_main_gui.hpp>
#include <cTab_Uav_gui.hpp>
#include <cTab_Hcam_gui.hpp>

//Old Android 
//#include <cTab_android_gui.hpp>
//New Android Gui
#include <\cTab\android\cTab_android_gui_new.hpp>


#include <cTab_veh_gui.hpp>
#include <\cTab\msg\msg_ctab_gui.hpp>
#include <\cTab\TAD\cTab_TAD_dialog.hpp>
#include <\cTab\microDAGR\cTab_microDAGR_dialog.hpp>
#include <\cTab\msg\android_msg_gui.hpp>

class CfgWeapons
{
	class ItemCore;
 	class InventoryItem_Base_F;
	class ItemcTab: ItemCore {
		descriptionshort = "DK10 Rugged Tablet PC";
		descriptionuse = "<t color='#9cf953'>Use: </t>Show Commander's Tablet";
		displayname = "Rugged Tablet";
		picture = "\cTab\img\15th_rugged_tab_ico.paa";
		scope = 2;
		simulation = "ItemGPS";
		class ItemInfo {
			mass = 56;
		};
		author = AUTHOR;
	};
	
	class ItemAndroid: ItemcTab {
		author = "Raspu";
		descriptionshort = "GD300 Rugged Wearable Computer";
		descriptionuse = "<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname = "GD300 Android";
		picture = "\cTab\img\itemAndroid_icon.paa";
		model = "\ctab\data\itemAndroid.p3d";
		class ItemInfo {
			mass = 5;
		};	
	};

	class ItemMicroDAGR: ItemcTab {
		author = "Raspu";
		descriptionshort = "HNV-2930 Micro Defense Advanced GPS Receiver";
		descriptionuse = "<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname = "MicroDAGR";
		picture = "\cTab\img\itemMicroDAGR_icon.paa";
		model = "\ctab\data\itemMicroDAGR.p3d";
		class ItemInfo {
			mass = 6;
		};	
	};
	
	class ItemcTabHCam: ItemCore {
		descriptionshort = "HD Helmet Mounted Camera";
		descriptionuse = "<t color='#9cf953'>Use: </t>Used to record and stream video";
		displayname = "Helmet Camera";
		picture = "\cTab\img\cTab_helmet_cam_ico.paa";
		scope = 2;
		class ItemInfo: InventoryItem_Base_F {
			mass = 4;
			type = 201;
		};
	};	
};

class CfgNotifications
{
	
	class cTabUavNotAval
	{
		title = "cTab";
		iconPicture = "\cTab\img\15th_rugged_tab_ico.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "%1";
		duration = 5;
		priority = 7;
		difficulty[] = {};
	};
	
	class cTabNewMsg
	{
		title = "cTab";
		iconPicture = "\cTab\img\icoUnopenedmail.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "%1";
		duration = 4;
		priority = 7;
		difficulty[] = {};
	};

	class cTabMsgSent
	{
		title = "cTab";
		iconPicture = "\cTab\img\icoUnopenedmail.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "Your message has been sent.";
		duration = 4;
		priority = 7;
		difficulty[] = {};
	};	

};

class RscTitles
{
	titles[]={};
	#include <\cTab\msg\msg_mail_title.hpp>
	#include <\cTab\TAD\cTab_TAD_gui.hpp>
	#include <\cTab\microDAGR\cTab_microDAGR_display.hpp>
};


class CfgVehicles
{

	class Box_NATO_WpsSpecial_F;
	class Box_cTab_items : Box_NATO_WpsSpecial_F {
		displayname = "[cTab] Computer Gear";
		icon = "iconCrateLarge";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		scope = 2;
		transportmaxmagazines = 64;
		transportmaxweapons = 12;

		class TransportItems {
			class _xx_ItemcTab {
				count = 5;
				name = "ItemcTab";
			};
			class _xx_ItemAndroid {
				count = 15;
				name = "ItemAndroid";
			};
			class _xx_ItemMicroDAGR {
				count = 25;
				name = "ItemMicroDAGR";
			};
			class _xx_ItemcTabHCam {
				count = 25;
				name = "ItemcTabHCam";
			};
		};
	
	
		class TransportMagazines {};
		class TransportWeapons {};
	
	};
	
};




