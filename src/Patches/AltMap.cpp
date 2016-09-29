#include "AltMap.hpp"
#include "../Patch.hpp"
#include "../ElDorito.hpp"
#include "../Blam/BlamTypes.hpp"
#include "../Modules/ModuleServer.hpp"

#include <windows.h>
#include <iostream>

namespace Patches
{
	namespace AltMap
	{
		void SetAltMap(int value)
		{
			//If Enabled, write the alternate map data.

			if (value)
			{
				//Auto pointer system.

				HANDLE getED = GetCurrentProcess();
				DWORD tagIndexTable = 0x22AAFFC;
				DWORD tagAddressTable = 0x22AAFF8;
				DWORD mapAddress = 0x22AB039;

				DWORD data1;
				DWORD data2;
				DWORD data3;
				DWORD data4;

				ReadProcessMemory(getED, (void*)(tagIndexTable), &data1, sizeof(data1), 0);
				ReadProcessMemory(getED, (void*)(tagAddressTable), &data3, sizeof(data3), 0);

				int mapValue;

				ReadProcessMemory(getED, (void*)(mapAddress), &mapValue, sizeof(mapValue), 0);

				if (mapValue == 1702259058)
				{
					//Set map lighting.

					DWORD lbsp = 0x3A0B;

					ReadProcessMemory(getED, (void*)((4 * lbsp) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD lbspAddress = data4;

					DWORD shadows = 0x47CF4;
					DWORD midtones = 0x47D0C;
					DWORD highlights = 0x47D24;
					DWORD tdwhites = 0x47D3C;
					DWORD tdblacks = 0x47D54;

					int setshadows = (1017370378);
					int setmidtones = (981668463);
					int sethighlights = (981668463);
					int settdwhites = (1025758986);
					int settdblacks = (1017370378);

					WriteProcessMemory(getED, (void*)(lbspAddress + shadows), &setshadows, sizeof(setshadows), 0);
					WriteProcessMemory(getED, (void*)(lbspAddress + midtones), &setmidtones, sizeof(setmidtones), 0);
					WriteProcessMemory(getED, (void*)(lbspAddress + highlights), &sethighlights, sizeof(sethighlights), 0);
					WriteProcessMemory(getED, (void*)(lbspAddress + tdwhites), &settdwhites, sizeof(settdwhites), 0);
					WriteProcessMemory(getED, (void*)(lbspAddress + tdblacks), &settdblacks, sizeof(settdblacks), 0);

					//Set map lighting.

					DWORD skya = 0x34CE;

					ReadProcessMemory(getED, (void*)((4 * skya) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD skyaAddress = data4;

					DWORD brightness = 0x4C;
					DWORD intensity = 0x54;
					DWORD brightness2 = 0xF0;
					DWORD intensity2 = 0xF8;
					DWORD skyinvis = 0xFE;
					DWORD brightness3 = 0x238;
					DWORD intensity3 = 0x240;
					DWORD skyinvis2 = 0x246;

					int setbrightness = (981668463);
					int setintensity = (981668463);
					int setskyinvis = (1546239872);
					int setskyinvis2 = (1546208150);

					WriteProcessMemory(getED, (void*)(skyaAddress + brightness), &setbrightness, sizeof(setbrightness), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + intensity), &setintensity, sizeof(setintensity), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + brightness2), &setbrightness, sizeof(setbrightness), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + intensity2), &setintensity, sizeof(setintensity), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + skyinvis), &setskyinvis, sizeof(setskyinvis), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + brightness3), &setbrightness, sizeof(setbrightness), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + intensity3), &setintensity, sizeof(setintensity), 0);
					WriteProcessMemory(getED, (void*)(skyaAddress + skyinvis2), &setskyinvis2, sizeof(setskyinvis2), 0);

					//Set character lighting.

					DWORD chmt = 0x34CF;

					ReadProcessMemory(getED, (void*)((4 * chmt) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD chmtAddress = data4;

					DWORD lightmapbrightness = 0x33;

					int setlightmapbrightness = (190);

					WriteProcessMemory(getED, (void*)(chmtAddress + lightmapbrightness), &setlightmapbrightness, sizeof(setlightmapbrightness), 0);

					//Fix glowing geometry.

					DWORD sbsp = 0x3489;

					ReadProcessMemory(getED, (void*)((4 * sbsp) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD sbspAddress = data4;

					DWORD geoinstance12bit6 = 0x32886;
					DWORD geoinstance13bit6 = 0x328FA;
					DWORD geoinstance297bit6 = 0x3A9AA;
					DWORD geoinstance301bit6 = 0x3AB7A;

					int setgeoinstance12bit6 = (72);
					int setgeoinstance13bit6 = (72);
					int setgeoinstance297bit6 = (66);
					int setgeoinstance301bit6 = (66);

					WriteProcessMemory(getED, (void*)(sbspAddress + geoinstance12bit6), &setgeoinstance12bit6, sizeof(setgeoinstance12bit6), 0);
					WriteProcessMemory(getED, (void*)(sbspAddress + geoinstance13bit6), &setgeoinstance13bit6, sizeof(setgeoinstance13bit6), 0);
					WriteProcessMemory(getED, (void*)(sbspAddress + geoinstance297bit6), &setgeoinstance297bit6, sizeof(setgeoinstance297bit6), 0);
					WriteProcessMemory(getED, (void*)(sbspAddress + geoinstance301bit6), &setgeoinstance301bit6, sizeof(setgeoinstance301bit6), 0);

					//Fix glowing aerial.

					DWORD mode = 0x35BA;

					ReadProcessMemory(getED, (void*)((4 * mode) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD modeAddress = data4;

					DWORD unknown1A = 0x401E4;
					DWORD unknown2A = 0x401E8;
					DWORD unknown3A = 0x401EC;
					DWORD unknown4A = 0x401F0;
					DWORD unknown5A = 0x401F4;
					DWORD unknown6A = 0x401F8;
					DWORD unknown7A = 0x401FC;
					DWORD unknown8A = 0x40200;
					DWORD unknown9A = 0x40204;
					DWORD unknown1B = 0x40224;
					DWORD unknown2B = 0x40228;
					DWORD unknown3B = 0x4022C;
					DWORD unknown4B = 0x40230;
					DWORD unknown5B = 0x40234;
					DWORD unknown6B = 0x40238;
					DWORD unknown7B = 0x4023C;
					DWORD unknown8B = 0x40240;
					DWORD unknown9B = 0x40244;
					DWORD unknown1C = 0x40264;
					DWORD unknown2C = 0x40268;
					DWORD unknown3C = 0x4026C;
					DWORD unknown4C = 0x40270;
					DWORD unknown5C = 0x40274;
					DWORD unknown6C = 0x40278;
					DWORD unknown7C = 0x4027C;
					DWORD unknown8C = 0x40280;
					DWORD unknown9C = 0x40284;

					int setunknown1A = (1008981770);
					int setunknown9A = (974997842);
					int setunknown1B = (1008981770);
					int setunknown9B = (973279855);
					int setunknown1C = (1008981770);
					int setunknown9C = (970045207);
					int setunknownXX = (0);

					WriteProcessMemory(getED, (void*)(modeAddress + unknown1A), &setunknown1A, sizeof(setunknown1A), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown2A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown3A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown4A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown5A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown6A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown7A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown8A), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown9A), &setunknown9A, sizeof(setunknown9A), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown1B), &setunknown1B, sizeof(setunknown1B), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown2B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown3B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown4B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown5B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown6B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown7B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown8B), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown9B), &setunknown9B, sizeof(setunknown9B), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown1C), &setunknown1C, sizeof(setunknown1C), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown2C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown3C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown4C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown5C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown6C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown7C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown8C), &setunknownXX, sizeof(setunknownXX), 0);
					WriteProcessMemory(getED, (void*)(modeAddress + unknown9C), &setunknown9C, sizeof(setunknown9C), 0);

					//Fix glowing warthog ambient.

					DWORD hlmt = 0x3625;

					ReadProcessMemory(getED, (void*)((4 * hlmt) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD hlmtAddress = data4;

					DWORD collision = 0x10C;

					int setcollision = (4294967295);

					WriteProcessMemory(getED, (void*)(hlmtAddress + collision), &setcollision, sizeof(setcollision), 0);

					//Fix glowing warthog palette.

					DWORD rmsh = 0x3629;

					ReadProcessMemory(getED, (void*)((4 * rmsh) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmshAddress = data4;

					DWORD rmsharg1 = 0x7B0;
					DWORD rmsharg2 = 0x7B4;
					DWORD rmsharg3 = 0x7B8;
					DWORD rmsharg4 = 0x7BC;

					int setrmshargs = (1008981770);

					WriteProcessMemory(getED, (void*)(rmshAddress + rmsharg1), &setrmshargs, sizeof(setrmshargs), 0);
					WriteProcessMemory(getED, (void*)(rmshAddress + rmsharg2), &setrmshargs, sizeof(setrmshargs), 0);
					WriteProcessMemory(getED, (void*)(rmshAddress + rmsharg3), &setrmshargs, sizeof(setrmshargs), 0);
					WriteProcessMemory(getED, (void*)(rmshAddress + rmsharg4), &setrmshargs, sizeof(setrmshargs), 0);

					//Fix glowing warthog palette.

					DWORD rmsh2 = 0x362A;

					ReadProcessMemory(getED, (void*)((4 * rmsh2) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmsh2Address = data4;

					DWORD rmsh2arg1 = 0xA04;
					DWORD rmsh2arg2 = 0xA08;
					DWORD rmsh2arg3 = 0xA0C;
					DWORD rmsh2arg4 = 0xA10;

					int setrmsh2args = (1008981770);

					WriteProcessMemory(getED, (void*)(rmsh2Address + rmsh2arg1), &setrmsh2args, sizeof(setrmsh2args), 0);
					WriteProcessMemory(getED, (void*)(rmsh2Address + rmsh2arg2), &setrmsh2args, sizeof(setrmsh2args), 0);
					WriteProcessMemory(getED, (void*)(rmsh2Address + rmsh2arg3), &setrmsh2args, sizeof(setrmsh2args), 0);
					WriteProcessMemory(getED, (void*)(rmsh2Address + rmsh2arg4), &setrmsh2args, sizeof(setrmsh2args), 0);

					//Fix glowing waterfall.

					DWORD rmsh3 = 0x34F4;

					ReadProcessMemory(getED, (void*)((4 * rmsh3) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmsh3Address = data4;

					DWORD rmsh3arg1 = 0xD7C;
					DWORD rmsh3arg2 = 0xD80;

					int setrmsh3args = (1036831949);

					WriteProcessMemory(getED, (void*)(rmsh3Address + rmsh3arg1), &setrmsh3args, sizeof(setrmsh3args), 0);
					WriteProcessMemory(getED, (void*)(rmsh3Address + rmsh3arg2), &setrmsh3args, sizeof(setrmsh3args), 0);

					//Fix glowing lakeriver.

					DWORD rmw = 0x34F9;

					ReadProcessMemory(getED, (void*)((4 * rmw) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmwAddress = data4;

					DWORD rmwarg1 = 0x1A2C;
					DWORD rmwarg2 = 0x1A30;
					DWORD rmwarg3 = 0x1A34;
					DWORD rmwarg4 = 0x1A38;

					int setrmwargs = (1101004800);

					WriteProcessMemory(getED, (void*)(rmwAddress + rmwarg1), &setrmwargs, sizeof(setrmwargs), 0);
					WriteProcessMemory(getED, (void*)(rmwAddress + rmwarg2), &setrmwargs, sizeof(setrmwargs), 0);
					WriteProcessMemory(getED, (void*)(rmwAddress + rmwarg3), &setrmwargs, sizeof(setrmwargs), 0);
					WriteProcessMemory(getED, (void*)(rmwAddress + rmwarg4), &setrmwargs, sizeof(setrmwargs), 0);

					//Fix glowing trees.

					DWORD rmsh4 = 0x34DF;

					ReadProcessMemory(getED, (void*)((4 * rmsh4) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmsh4Address = data4;

					DWORD rmsh4arg1 = 0x3DC;
					DWORD rmsh4arg2 = 0x3E0;
					DWORD rmsh4arg3 = 0x3E4;
					DWORD rmsh4arg4 = 0x3E8;

					int setrmsh4args = (1008981770);

					WriteProcessMemory(getED, (void*)(rmsh4Address + rmsh4arg1), &setrmsh4args, sizeof(setrmsh4args), 0);
					WriteProcessMemory(getED, (void*)(rmsh4Address + rmsh4arg2), &setrmsh4args, sizeof(setrmsh4args), 0);
					WriteProcessMemory(getED, (void*)(rmsh4Address + rmsh4arg3), &setrmsh4args, sizeof(setrmsh4args), 0);
					WriteProcessMemory(getED, (void*)(rmsh4Address + rmsh4arg4), &setrmsh4args, sizeof(setrmsh4args), 0);

					//Fix glowing trees.

					DWORD rmfl = 0x34F5;

					ReadProcessMemory(getED, (void*)((4 * rmfl) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmflAddress = data4;

					DWORD rmflarg1 = 0x240;
					DWORD rmflarg2 = 0x244;
					DWORD rmflarg3 = 0x248;
					DWORD rmflarg4 = 0x24C;

					int setrmflargs = (1008981770);

					WriteProcessMemory(getED, (void*)(rmflAddress + rmflarg1), &setrmflargs, sizeof(setrmflargs), 0);
					WriteProcessMemory(getED, (void*)(rmflAddress + rmflarg2), &setrmflargs, sizeof(setrmflargs), 0);
					WriteProcessMemory(getED, (void*)(rmflAddress + rmflarg3), &setrmflargs, sizeof(setrmflargs), 0);
					WriteProcessMemory(getED, (void*)(rmflAddress + rmflarg4), &setrmflargs, sizeof(setrmflargs), 0);

					//Fix glowing trees.

					DWORD rmfl2 = 0x34F6;

					ReadProcessMemory(getED, (void*)((4 * rmfl2) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmfl2Address = data4;

					DWORD rmfl2arg1 = 0x240;
					DWORD rmfl2arg2 = 0x244;
					DWORD rmfl2arg3 = 0x248;
					DWORD rmfl2arg4 = 0x24C;

					int setrmfl2args = (1008981770);

					WriteProcessMemory(getED, (void*)(rmfl2Address + rmfl2arg1), &setrmfl2args, sizeof(setrmfl2args), 0);
					WriteProcessMemory(getED, (void*)(rmfl2Address + rmfl2arg2), &setrmfl2args, sizeof(setrmfl2args), 0);
					WriteProcessMemory(getED, (void*)(rmfl2Address + rmfl2arg3), &setrmfl2args, sizeof(setrmfl2args), 0);
					WriteProcessMemory(getED, (void*)(rmfl2Address + rmfl2arg4), &setrmfl2args, sizeof(setrmfl2args), 0);

					//Fix glowing trees.

					DWORD rmfl3 = 0x34F7;

					ReadProcessMemory(getED, (void*)((4 * rmfl3) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD rmfl3Address = data4;

					DWORD rmfl3arg1 = 0x240;
					DWORD rmfl3arg2 = 0x244;
					DWORD rmfl3arg3 = 0x248;
					DWORD rmfl3arg4 = 0x24C;

					int setrmfl3args = (1008981770);

					WriteProcessMemory(getED, (void*)(rmfl3Address + rmfl3arg1), &setrmfl3args, sizeof(setrmfl3args), 0);
					WriteProcessMemory(getED, (void*)(rmfl3Address + rmfl3arg2), &setrmfl3args, sizeof(setrmfl3args), 0);
					WriteProcessMemory(getED, (void*)(rmfl3Address + rmfl3arg3), &setrmfl3args, sizeof(setrmfl3args), 0);
					WriteProcessMemory(getED, (void*)(rmfl3Address + rmfl3arg4), &setrmfl3args, sizeof(setrmfl3args), 0);

					//Fix glowing decorators.

					DWORD dctr = 0x34FB;

					ReadProcessMemory(getED, (void*)((4 * dctr) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctrAddress = data4;

					DWORD affectsvisibility = 0x60;
					DWORD brightnessbase = 0x84;
					DWORD brightnessshadow = 0x88;

					int setaffectsvisibility = (1281);
					int setbrightnessbase = (1008981770);
					int setbrightnessshadow = (1008981770);

					WriteProcessMemory(getED, (void*)(dctrAddress + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctrAddress + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctrAddress + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr2 = 0x34FC;

					ReadProcessMemory(getED, (void*)((4 * dctr2) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr2Address = data4;

					WriteProcessMemory(getED, (void*)(dctr2Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr2Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr2Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr3 = 0x34FD;

					ReadProcessMemory(getED, (void*)((4 * dctr3) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr3Address = data4;

					WriteProcessMemory(getED, (void*)(dctr3Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr3Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr3Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr4 = 0x34FE;

					ReadProcessMemory(getED, (void*)((4 * dctr4) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr4Address = data4;

					WriteProcessMemory(getED, (void*)(dctr4Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr4Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr4Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr5 = 0x34FF;

					ReadProcessMemory(getED, (void*)((4 * dctr5) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr5Address = data4;

					WriteProcessMemory(getED, (void*)(dctr5Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr5Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr5Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr6 = 0x3500;

					ReadProcessMemory(getED, (void*)((4 * dctr6) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr6Address = data4;

					WriteProcessMemory(getED, (void*)(dctr6Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr6Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr6Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr7 = 0x3501;

					ReadProcessMemory(getED, (void*)((4 * dctr7) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr7Address = data4;

					WriteProcessMemory(getED, (void*)(dctr7Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr7Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr7Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr8 = 0x3502;

					ReadProcessMemory(getED, (void*)((4 * dctr8) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr8Address = data4;

					WriteProcessMemory(getED, (void*)(dctr8Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr8Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr8Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr9 = 0x3503;

					ReadProcessMemory(getED, (void*)((4 * dctr9) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr9Address = data4;

					WriteProcessMemory(getED, (void*)(dctr9Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr9Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr9Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr10 = 0x3504;

					ReadProcessMemory(getED, (void*)((4 * dctr10) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr10Address = data4;

					WriteProcessMemory(getED, (void*)(dctr10Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr10Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr10Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);

					DWORD dctr11 = 0x3505;

					ReadProcessMemory(getED, (void*)((4 * dctr11) + data1), &data2, sizeof(data2), 0);
					ReadProcessMemory(getED, (void*)((4 * data2) + data3), &data4, sizeof(data4), 0);
					DWORD dctr11Address = data4;

					WriteProcessMemory(getED, (void*)(dctr11Address + affectsvisibility), &setaffectsvisibility, sizeof(setaffectsvisibility), 0);
					WriteProcessMemory(getED, (void*)(dctr11Address + brightnessbase), &setbrightnessbase, sizeof(setbrightnessbase), 0);
					WriteProcessMemory(getED, (void*)(dctr11Address + brightnessshadow), &setbrightnessshadow, sizeof(setbrightnessshadow), 0);
				}

				if (mapValue == 1717527928)
				{
					//FlatGrass (Both)
				}
			}

			//If Disabled, write the original map data.

			else
			{
				//Do nothing.
			}
		}
	}
}
