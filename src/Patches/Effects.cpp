#include "Effects.hpp"
#include "../Patch.hpp"
#include "../ElDorito.hpp"
#include "../Blam/BlamTypes.hpp"
#include "../Modules/ModuleServer.hpp"

#include <windows.h>
#include <iostream>

namespace Patches
{
	namespace Effects
	{
		void SetEffects(int value)
		{
			auto &serverModule = Modules::ModuleServer::Instance();
			int getEffects = serverModule.VarServerSetEffectsClient->ValueInt;

			//If Enabled, write the modified effects data.

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

				//Set flashlight.

				DWORD bipd = 0x01DD;

				ReadProcessMemory(getED, (void*)((4 * bipd) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD bipdAddress = data4;

				DWORD flashlight1p = 0x3E0;
				DWORD flashlight3p = 0x404;

				int setflashlightOn = (510);
				int setflashlightOff = (579);

				//Set birthday.

				DWORD hlmt = 0x1348;

				ReadProcessMemory(getED, (void*)((4 * hlmt) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD hlmtAddress = data4;

				DWORD birthday = 0xC6C;

				int setbirthdayOn = (4862);
				int setbirthdayOff = (4942);

				if (getEffects == 1)
				{
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight1p), &setflashlightOn, sizeof(setflashlightOn), 0);
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight3p), &setflashlightOn, sizeof(setflashlightOn), 0);

					WriteProcessMemory(getED, (void*)(hlmtAddress + birthday), &setbirthdayOff, sizeof(setbirthdayOff), 0);
				}

				if (getEffects == 2)
				{
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight1p), &setflashlightOff, sizeof(setflashlightOff), 0);
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight3p), &setflashlightOff, sizeof(setflashlightOff), 0);

					WriteProcessMemory(getED, (void*)(hlmtAddress + birthday), &setbirthdayOn, sizeof(setbirthdayOn), 0);
				}

				if (getEffects == 3)
				{
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight1p), &setflashlightOn, sizeof(setflashlightOn), 0);
					WriteProcessMemory(getED, (void*)(bipdAddress + flashlight3p), &setflashlightOn, sizeof(setflashlightOn), 0);

					WriteProcessMemory(getED, (void*)(hlmtAddress + birthday), &setbirthdayOn, sizeof(setbirthdayOn), 0);
				}
			}

			//If Disabled, write the default effects data.

			else
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

				//Set flashlight.

				DWORD bipd = 0x01DD;

				ReadProcessMemory(getED, (void*)((4 * bipd) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD bipdAddress = data4;

				DWORD flashlight1p = 0x3E0;
				DWORD flashlight3p = 0x404;

				int setflashlight = (579);

				WriteProcessMemory(getED, (void*)(bipdAddress + flashlight1p), &setflashlight, sizeof(setflashlight), 0);
				WriteProcessMemory(getED, (void*)(bipdAddress + flashlight3p), &setflashlight, sizeof(setflashlight), 0);

				//Set birthday.

				DWORD hlmt = 0x1348;

				ReadProcessMemory(getED, (void*)((4 * hlmt) + data1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
				DWORD hlmtAddress = data4;

				DWORD birthday = 0xC6C;

				int setbirthday = (4942);

				WriteProcessMemory(getED, (void*)(hlmtAddress + birthday), &setbirthday, sizeof(setbirthday), 0);
			}
		}
	}
}
