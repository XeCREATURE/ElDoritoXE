#include "../Patches/AltMap.hpp"
#include "../Patches/Biped.hpp"
#include "../Patches/Effects.hpp"
#include "../Patches/Gravity.hpp"

namespace
{
	bool SetAltMapChanged(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		//Do a quick check to make sure we're not on the Main Menu.

		HANDLE getED = GetCurrentProcess();
		DWORD mapAddress = 0x22AB039;

		int mapValue;

		ReadProcessMemory(getED, (void*)(mapAddress), &mapValue, sizeof(mapValue), 0);

		if (mapValue != 1852399981)
		{
			Modules::CommandMap::Instance().ExecuteCommand("Game.Start");
		}

		//If altmap value is NOT 0 then set Enabled, else set Disabled.

		auto &serverModule = Modules::ModuleServer::Instance();
		auto value = serverModule.VarServerSetAltMapClient->ValueInt != 0;
		Patches::AltMap::SetAltMap(value);
		return true;
	}

	bool SetBipedChanged(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		//Do a quick check to make sure we're not on the Main Menu.

		HANDLE getED = GetCurrentProcess();
		DWORD mapAddress = 0x22AB039;

		int mapValue;

		ReadProcessMemory(getED, (void*)(mapAddress), &mapValue, sizeof(mapValue), 0);

		if (mapValue != 1852399981)
		{
			Modules::CommandMap::Instance().ExecuteCommand("Game.Start");
		}

		//If biped value is NOT 0 then set Enabled, else set Disabled.

		auto &serverModule = Modules::ModuleServer::Instance();
		auto value = serverModule.VarServerSetBipedClient->ValueInt != 0;
		Patches::Biped::SetBiped(value);
		return true;
	}

	bool SetEffectsChanged(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		//If effects value is NOT 0 then set Enabled, else set Disabled.

		auto &serverModule = Modules::ModuleServer::Instance();
		auto value = serverModule.VarServerSetEffectsClient->ValueInt != 0;
		Patches::Effects::SetEffects(value);
		return true;
	}

	bool SetGravityChanged(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		//If gravity value is NOT 4 then set Enabled, else set Disabled.

		auto &serverModule = Modules::ModuleServer::Instance();
		auto value = serverModule.VarServerSetGravityClient->ValueFloat != 4;
		Patches::Gravity::SetGravity(value);
		return true;
	}
}

namespace Modules
{
	ModuleServer::ModuleServer() : ModuleBase("Server")
	{
		VarServerSetAltMap = AddVariableInt("SetAltMap", "altmap", "Toggles map alternates on the server. 0 = Disabled; 1 = Enabled;", static_cast<CommandFlags>(eCommandFlagsHostOnly | eCommandFlagsArchived | eCommandFlagsReplicated), 0);
		VarServerSetAltMap->ValueIntMin = 0;
		VarServerSetAltMap->ValueIntMax = 1;
		VarServerSetAltMapClient = AddVariableInt("SetAltMapClient", "altmap_client", "", eCommandFlagsInternal, 0, SetAltMapChanged);
		VarServerSetAltMapClient->ValueIntMin = 0;
		VarServerSetAltMapClient->ValueIntMax = 1;
		Server::VariableSynchronization::Synchronize(VarServerSetAltMap, VarServerSetAltMapClient);

		VarServerSetBiped = AddVariableInt("SetBiped", "biped", "Sets the character on the server. 0 = Spartan; 1 = Elite;", static_cast<CommandFlags>(eCommandFlagsHostOnly | eCommandFlagsArchived | eCommandFlagsReplicated), 0);
		VarServerSetBiped->ValueIntMin = 0;
		VarServerSetBiped->ValueIntMax = 1;
		VarServerSetBipedClient = AddVariableInt("SetBipedClient", "biped_client", "", eCommandFlagsInternal, 0, SetBipedChanged);
		VarServerSetBipedClient->ValueIntMin = 0;
		VarServerSetBipedClient->ValueIntMax = 1;
		Server::VariableSynchronization::Synchronize(VarServerSetBiped, VarServerSetBipedClient);

		VarServerSetEffects = AddVariableInt("SetEffects", "effects", "Toggles effects on the server. 0 = Disabled; 1 = Flashlight; 2 = Birthday; 3 = Both;", static_cast<CommandFlags>(eCommandFlagsHostOnly | eCommandFlagsArchived | eCommandFlagsReplicated), 0);
		VarServerSetEffects->ValueIntMin = 0;
		VarServerSetEffects->ValueIntMax = 3;
		VarServerSetEffectsClient = AddVariableInt("SetEffectsClient", "effects_client", "", eCommandFlagsInternal, 0, SetEffectsChanged);
		VarServerSetEffectsClient->ValueIntMin = 0;
		VarServerSetEffectsClient->ValueIntMax = 3;
		Server::VariableSynchronization::Synchronize(VarServerSetEffects, VarServerSetEffectsClient);

		VarServerSetGravity = AddVariableFloat("SetGravity", "gravity", "Sets the gravity on the server. 0 = Min; 50 = Max; 4 = Default;", static_cast<CommandFlags>(eCommandFlagsHostOnly | eCommandFlagsArchived | eCommandFlagsReplicated), 4);
		VarServerSetGravity->ValueFloatMin = 0;
		VarServerSetGravity->ValueFloatMax = 50;
		VarServerSetGravityClient = AddVariableFloat("SetGravityClient", "gravity_client", "", eCommandFlagsInternal, 4, SetGravityChanged);
		VarServerSetGravityClient->ValueFloatMin = 0;
		VarServerSetGravityClient->ValueFloatMax = 50;
		Server::VariableSynchronization::Synchronize(VarServerSetGravity, VarServerSetGravityClient);
	}
}
