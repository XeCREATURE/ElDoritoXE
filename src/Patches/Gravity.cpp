#include "Gravity.hpp"
#include "../Patch.hpp"
#include "../ElDorito.hpp"
#include "../Blam/BlamTypes.hpp"
#include "../Modules/ModuleServer.hpp"

namespace Patches
{
	namespace Gravity
	{
		void SetGravity(float value)
		{
			auto &serverModule = Modules::ModuleServer::Instance();
			float resetGravity = (GameGlobals::Physics::DefaultGravity);
			float newGravity = serverModule.VarServerSetGravityClient->ValueFloat;

			//If Enabled, write the new gravity value.

			if (value)
			{
				auto &gravityPtr = ElDorito::GetMainTls(GameGlobals::Physics::TLSOffset)[0];
				if (&gravityPtr)
					gravityPtr(GameGlobals::Physics::GravityIndex).Write<float>(newGravity);
			}

			//If Disabled, write the default gravity value.

			else
			{
				auto &gravityPtr = ElDorito::GetMainTls(GameGlobals::Physics::TLSOffset)[0];
				if (&gravityPtr)
					gravityPtr(GameGlobals::Physics::GravityIndex).Write<float>(resetGravity);
			}
		}
	}
}
