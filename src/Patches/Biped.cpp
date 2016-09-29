#include "Biped.hpp"
#include "../Patch.hpp"
#include "../ElDorito.hpp"
#include "../Blam/BlamTypes.hpp"
#include "../Modules/ModuleServer.hpp"

#include <windows.h>
#include <iostream>

namespace Patches
{
	namespace Biped
	{
		void SetBiped(int value)
		{
			//If Enabled, write the elite biped data.

			if (value)
			{
				//Auto pointer system.

				HANDLE getED = GetCurrentProcess();
				DWORD tagIndexTable = 0x22AAFFC;
				DWORD tagAddressTable = 0x22AAFF8;
				
				DWORD data1;
				DWORD data2;
				DWORD data3;
				DWORD data4;
				
				ReadProcessMemory(getED, (void*)(tagIndexTable), &data1, sizeof(data1), 0);
				ReadProcessMemory(getED, (void*)(tagAddressTable), &data3, sizeof(data3), 0);
				
				//Set the Biped.
				
				DWORD matg = 0x0016;

				ReadProcessMemory(getED, (void*)((4 * matg) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD matgAddress = data4;

				DWORD biped = 0x662C;
				DWORD fpArms = 0x660C;
				DWORD fpLegs = 0x661C;
				DWORD mannequin = 0x68B4;
				DWORD podium = 0x698C;

				int setbiped = (482);
				int setfpArms = (480);
				int setfpLegs = (481);
				int setmannequin = (486);
				int setpodium = (488);

				WriteProcessMemory(getED, (void*)(matgAddress + biped), &setbiped, sizeof(setbiped), 0);
				WriteProcessMemory(getED, (void*)(matgAddress + fpArms), &setfpArms, sizeof(setfpArms), 0);
				WriteProcessMemory(getED, (void*)(matgAddress + fpLegs), &setfpLegs, sizeof(setfpLegs), 0);
				WriteProcessMemory(getED, (void*)(matgAddress + mannequin), &setmannequin, sizeof(setmannequin), 0);
				WriteProcessMemory(getED, (void*)(matgAddress + podium), &setpodium, sizeof(setpodium), 0);

				//Update the Armory.

				DWORD mulg = 0x028E;

				ReadProcessMemory(getED, (void*)((4 * mulg) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD mulgAddress = data4;

				/*
				These pointers can change based on the Armory.
				Once done setting this up at max, make loop.
				This setup is for FlatGrass.
				*/

				DWORD helmetBase = 0x440;
				DWORD chestBase = 0x13A0;
				DWORD shouldersBase = 0x2330;
				DWORD armsBase = 0x32C0;
				DWORD armsfpBase = 0x32D0;
				DWORD legsBase = 0x3C50;
				DWORD pelvisBase = 0x4AF0;

				int setBase = (29444);
				int setfpBase = (30562);

				int setArmor2 = (29644);
				int setfpArmor2 = (30719);

				int setArmor3 = (29738);
				int setfpArmor3 = (30789);

				WriteProcessMemory(getED, (void*)(mulgAddress + helmetBase), &setBase, sizeof(setBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + chestBase), &setBase, sizeof(setBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + shouldersBase), &setBase, sizeof(setBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + armsBase), &setBase, sizeof(setBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + armsfpBase), &setfpBase, sizeof(setfpBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + legsBase), &setBase, sizeof(setBase), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + pelvisBase), &setBase, sizeof(setBase), 0);

				int blockSize = 48;
				std::stringstream stream;
				stream << std::hex << blockSize;

				int setDefault = (setBase);
				int setfpDefault = (setfpBase);

				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 2))), &setArmor2, sizeof(setArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 3))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 12))), &setArmor3, sizeof(setArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 13))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 16))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 17))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 18))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 20))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 23))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 27))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 29))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 30))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 34))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 36))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 41))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 47))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 54))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 56))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 57))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 58))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 63))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 67))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 68))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 69))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 79))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (helmetBase + (blockSize * 80))), &setDefault, sizeof(setDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 2))), &setArmor2, sizeof(setArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 3))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 12))), &setArmor3, sizeof(setArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 13))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 16))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 17))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 18))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 20))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 23))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 27))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 29))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 30))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 34))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 36))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 41))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 47))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 54))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 56))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 57))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 62))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 63))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 67))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 68))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 69))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 79))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 80))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (chestBase + (blockSize * 82))), &setDefault, sizeof(setDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 2))), &setArmor2, sizeof(setArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 3))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 12))), &setArmor3, sizeof(setArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 13))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 16))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 17))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 18))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 20))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 23))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 27))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 29))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 30))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 34))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 36))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 41))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 47))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 54))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 56))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 57))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 61))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 62))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 67))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 68))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 69))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 79))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 80))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (shouldersBase + (blockSize * 82))), &setDefault, sizeof(setDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 1))), &setArmor2, sizeof(setArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 6))), &setArmor3, sizeof(setArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 7))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 10))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 11))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 12))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 14))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 17))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 21))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 25))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 26))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 29))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 30))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 33))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 34))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 35))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 38))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 39))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 41))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 43))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 44))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 45))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 46))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 47))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 48))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 49))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsBase + (blockSize * 50))), &setDefault, sizeof(setDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 1))), &setfpArmor2, sizeof(setfpArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 6))), &setfpArmor3, sizeof(setfpArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 7))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 10))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 11))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 12))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 14))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 17))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 21))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 25))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 26))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 29))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 30))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 33))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 34))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 35))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 38))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 39))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 41))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 43))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 44))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 45))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 46))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 47))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 48))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 49))), &setfpDefault, sizeof(setfpDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (armsfpBase + (blockSize * 50))), &setfpDefault, sizeof(setfpDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 1))), &setArmor2, sizeof(setArmor2), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 5))), &setArmor3, sizeof(setArmor3), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 6))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 9))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 10))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 11))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 13))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 16))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 20))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 24))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 25))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 29))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 30))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 33))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 34))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 37))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 39))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 40))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 41))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 42))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 43))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 44))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 45))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 46))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 47))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 48))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 49))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 50))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 51))), &setDefault, sizeof(setDefault), 0);
				WriteProcessMemory(getED, (void*)(mulgAddress + (legsBase + (blockSize * 52))), &setDefault, sizeof(setDefault), 0);

				WriteProcessMemory(getED, (void*)(mulgAddress + (pelvisBase + (blockSize * 4))), &setDefault, sizeof(setDefault), 0);
			}

			//If Disabled, write the spartan biped data.

			else
			{
				//Do nothing.
			}
		}
	}
}
