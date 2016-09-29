#include "Patches\AltMap.hpp"
#include "Patches\Biped.hpp"
#include "Patches\Effects.hpp"
#include "Patches\Gravity.hpp"

#include "Modules\ModuleServer.hpp"

namespace Patches
{
	void Tick()
	{
		/*
		I know this is horrible but I cant figure out how to make this happen on Set{Patch}Changed,
		if someone would fix this I'd be really grateful. - Pokes patch value on every tick.
		*/

		auto &serverModule = Modules::ModuleServer::Instance();
		{
			auto value = serverModule.VarServerSetAltMapClient->ValueInt != 0;
			Patches::AltMap::SetAltMap(value);
		}

		{
			auto value = serverModule.VarServerSetBipedClient->ValueInt != 0;
			Patches::Biped::SetBiped(value);
		}

		{
			auto value = serverModule.VarServerSetEffectsClient->ValueInt != 0;
			Patches::Effects::SetEffects(value);
		}

		{
			auto value = serverModule.VarServerSetGravityClient->ValueFloat != 4;
			Patches::Gravity::SetGravity(value);
		}
	}
}
